/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/08/01 18:28:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_ints(t_pusha *stacks, char *input)
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
}

int	check_ints(t_pusha *stacks, int ac, char **input)
{
	int		ret;
	int		count;

	ret = 0;
	count = 1;
	while (count < ac)
	{
		ret = validate_ints(stacks, input[count]);
		//ft_printf("validate_ints return: %d\n", ret);
		if (ret == -1)
			return (ret);
		count++;
	}
	return (1);
}