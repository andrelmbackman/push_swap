/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/07/08 15:49:51 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_ints(t_pusha *stacks, char *input)
{
	long long	tmp;
	t_stack		*tmpstack;

	tmp = ft_atoll(input);
	tmpstack = stacks->a_stack;
	//ft_printf("Arg after ft_atoll: %ld\n", tmp);
	if (!ft_isdigit(input[0]) && input[0] != '-')
		return (free_stacks(stacks, ERROR));
	else if (tmp > 2147483647 || tmp < -2147483648)
		return (free_stacks(stacks, ERROR));
	while (tmpstack)
	{
		if ((int)tmp == tmpstack->num)
			return (free_stacks(stacks, ERROR));
		tmpstack = tmpstack->next;
	}
	if (!add_stack(&stacks->a_stack, (int)tmp))
		return (free_stacks(stacks, ERROR));
	else
		stacks->a_size++;
	//ft_printf("args: %li\n", tmp);
	//stacks->a_stack = head;
	return (1);
}

int	check_ints(t_pusha *stacks, int ac, char **input)
{
	int		ret;
	int		count;

	ret = 0;
	count = 2;
	while (count <= ac)
	{
		ret = validate_ints(stacks, input[count - 1]);
		//ft_printf("validate_ints return: %d\n", ret);
		if (ret == -1)
			return (ret);
		count++;
	}
	return (1);
}