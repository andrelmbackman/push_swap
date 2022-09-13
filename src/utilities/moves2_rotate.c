/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:28 by abackman          #+#    #+#             */
/*   Updated: 2022/09/13 17:45:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_ra(t_pusha *stacks)
{
	if (!stacks->a_stack)
		return (0);
	stacks->a_stack = stacks->a_stack->next;
	if (stacks->print == 1)
		write(1, "ra\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

int	exec_rb(t_pusha *stacks)
{
	if (!stacks->b_stack)
		return (0);
	stacks->b_stack = stacks->b_stack->next;
	if (stacks->print == 1)
		write(1, "rb\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

int	exec_rr(t_pusha *stacks)
{
	int	ret;

	ret = 0;
	if (stacks->v)
		stacks->v = 2;
	if (stacks->print)
		stacks->print = 2;
	ret = exec_ra(stacks);
	if (exec_rb(stacks) == 1)
		ret = 1;
	if (stacks->print == 2)
	{
		write(1, "rr\n", 3);
		stacks->print = 1;
	}
	if (stacks->v == 2)
	{
		print_stacks(stacks);
		stacks->v = 1;
	}
	return (ret);
}