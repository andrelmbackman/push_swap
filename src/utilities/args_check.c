/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/08/23 18:00:55 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_dup(t_stack *stack, long long num)
{
	t_stack	*tmp;
	//t_stack	*head;

	tmp = stack;
	//head = stack;
	while (tmp->next != stack && tmp != NULL)
	{
		if ((int)num == tmp->num)
			return (-1);
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		if (num == tmp->num)
			return (-1);
	}
	return (1);
}

static int	validate_ints(t_pusha *stacks, char *input)
{
	long long	tmpnum;
	int			ret;
	//t_stack		*head;

	tmpnum = ft_atoll(input);
	ret = 0;
	//head = stacks->a_stack;
	//ft_printf("Arg after ft_atoll: %ld\n", tmpnum);
	if (!ft_isdigit(input[0]) && input[0] != '-')
		return (free_stacks(stacks, ERROR));
	else if (tmpnum > 2147483647 || tmpnum < -2147483648)
		return (free_stacks(stacks, ERROR));
	if (!stacks->empty && stacks->a_stack != NULL)
		ret = check_dup(stacks->a_stack, tmpnum);
	if (ret == -1)
		return (free_stacks(stacks, ERROR));
	if (!add_stack(&stacks->a_stack, (int)tmpnum))
		return (free_stacks(stacks, ERROR));
	else
		stacks->a_size++;
	stacks->empty = 0;
	//ft_printf("\narg: %li\na_stack: %d\ntop: %d\n\n", tmpnum, stacks->a_stack->num, stacks->a_stack->top);
	//stacks->a_stack = head;
	return (1);
}

/* static int	validate_ints(t_pusha *stacks, char *input)
{
	long long	tmpnum;
	t_stack		*tmpstack;
	t_stack		*head;
	tmpnum = ft_atoll(input);
	if (!ft_isdigit(input[0]) && input[0] != '-')
		return (free_stacks(stacks, ERROR));
	else if (tmpnum > 2147483647 || tmpnum < -2147483648)
		return (free_stacks(stacks, ERROR));
	tmpstack = stacks->a_stack;
	head = stacks->a_stack;
	if (!stacks->empty)
	{
		while (tmpstack->next != head && tmpstack != NULL)
		{
			ft_printf("\nARE WE IN?\n");
			if ((int)tmpnum == tmpstack->num)
				return (free_stacks(stacks, ERROR));
			tmpstack = tmpstack->next;
		}
	}
	ft_printf("Arg after ft_atoll: %ld\n", tmpnum);
	if (!add_stack(&stacks->a_stack, (int)tmpnum))
		return (free_stacks(stacks, ERROR));
	else
		stacks->a_size++;
	stacks->empty = 0;
	ft_printf("args: %li\n", tmpnum);
	//stacks->a_stack = head;
	return (1);
} */
static int	validate_string(t_pusha *stacks, char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '-' && str[i] != '+' && \
		!ft_isdigit((int)str[i]))
			i++;
		ret = validate_ints(stacks, &str[i]);
		while (str[i] && (str[i] == '-' || str[i] == '+' || \
		ft_isdigit((int)str[i])))
			i++;
	}
	return (ret);
}

int	check_ints(t_pusha *stacks, int ac, char **input)
{
	int		ret;
	int		count;

	//t_stack *check;

	ret = 0;
	count = 1;
	stacks->min = 2147483647;
	stacks->max = -2147483648;
	while (count < ac)
	{
		//ret = validate_ints(stacks, input[count]);
		ret = validate_string(stacks, input[count]);
		//ft_printf("validate_ints return: %d\n", ret);
		if (ret == -1)
			return (ret);
		if (stacks->a_stack->prev->num > stacks->max)
			stacks->max = stacks->a_stack->prev->num;
		if (stacks->a_stack->prev->num < stacks->min)
			stacks->min = stacks->a_stack->prev->num;
		count++;
	}
/* 	check = stacks->a_stack;
	while (check->next != stacks->a_stack)
	{
		ft_printf("num: %d\n", check->num);
		check = check->next;
	}
	ft_printf("num: %d\n", check->num); */
	return (1);
}