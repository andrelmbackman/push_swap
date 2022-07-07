/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/07/07 16:44:27 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_ints(t_pusha *stacks, char *input)
{
	long long	tmp;
	t_stack		*head;

	tmp = ft_atoi(input);
	head = stacks->a_stack;
	if (!ft_isdigit(input[0]) && input[0] != '-')
		return (free_stacks(stacks, ERROR));
	else if (tmp > 2147483647 || tmp < -2147483648)
		return (free_stacks(stacks, ERROR));
	while (stacks->a_stack)
	{
		if (tmp == stacks->a_stack->num)
			return (free_stacks(stacks, ERROR));
		stacks->a_stack = stacks->a_stack->next;
	}
	stacks->a_stack = add_stack((int)tmp);
	ft_printf("args: %li\n", tmp);
	if (stacks->a_stack == NULL)
		return (free_stacks(stacks, ERROR));
	stacks->a_stack = head;
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