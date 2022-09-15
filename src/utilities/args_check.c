/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 15:16:30 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Returns -1 if a duplicate of num is found in the stack and 1 if not.
*/

static int	check_dup(t_stack *stack, long long num)
{
	t_stack	*tmp;

	tmp = stack;
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

/*
** ft_atoll (ascii to long long) is called, and if the number is between
** INT_MIN and INT_MAX it is added to the stack (unless a duplicate is found).
*/

static int	validate_ints(t_pusha *stacks, char *input)
{
	long long	tmpnum;
	int			ret;

	tmpnum = ft_atoll(input);
	ret = 0;
	if (tmpnum > 2147483647 || tmpnum < -2147483648)
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
	if ((int)tmpnum > stacks->max)
		stacks->max = (int)tmpnum;
	if ((int)tmpnum < stacks->min)
		stacks->min = (int)tmpnum;
	return (1);
}

/*
** Returns 1 if the string is found to contain invalid characters, 0 if not.
*/

static int	invalid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr((const char *)"1234567890+- ", (int)str[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** Checks the argument string for the -v flag, for invalid characters and lastly
** for integers.
*/

static int	validate_string(t_pusha *stacks, char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!ft_strncmp((const char *)str, (const char *)"-v", 2))
	{
		stacks->v = 1;
		str += 2;
	}
	if (invalid_chars(str))
		return (free_stacks(stacks, ERROR));
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

/*
** Iterates through all the arguments and calls validate_string to check them.
*/

int	check_ints(t_pusha *stacks, int ac, char **input)
{
	int		ret;
	int		count;

	ret = 0;
	count = 1;
	stacks->min = 2147483647;
	stacks->max = -2147483648;
	while (count < ac)
	{
		ret = validate_string(stacks, input[count]);
		if (ret == -1)
			return (-1);
		count++;
	}
	return (1);
}
