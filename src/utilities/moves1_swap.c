/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/09/13 17:54:05 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_sa(t_pusha *stacks)
{
	int	tmp;

	if (stacks->a_size < 2)
		return (0);
	tmp = stacks->a_stack->num;
	stacks->a_stack->num = stacks->a_stack->next->num;
	stacks->a_stack->next->num = tmp;
	if (stacks->print == 1)
		write(1, "sa\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

int	exec_sb(t_pusha *stacks)
{
	int	tmp;

	if (stacks->b_size < 2)
		return (0);
	tmp = stacks->b_stack->num;
	stacks->b_stack->num = stacks->b_stack->next->num;
	stacks->b_stack->next->num = tmp;
	if (stacks->print == 1)
		write(1, "sb\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

int	exec_ss(t_pusha *stacks)
{
	if (stacks->print)
		stacks->print = 2;
	if (stacks->v)
		stacks->v = 2;
	if (!exec_sa(stacks) && !exec_sb(stacks))
	{
		if (stacks->print == 2)
			stacks->print = 1;
		return (0);
	}
	else if (stacks->print == 2)
	{
		write(1, "ss\n", 3);
		stacks->print = 1;
	}
	if (stacks->v == 2)
	{
		print_stacks(stacks);
		stacks->v = 1;
	}
	return (1);
}
