/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:28 by abackman          #+#    #+#             */
/*   Updated: 2022/08/30 11:29:27 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_ra(t_pusha *stacks)
{
	if (!stacks->a_stack)
		return (0);
	stacks->a_stack = stacks->a_stack->next;
	if (stacks->print)
		write(1, "ra\n", 3);
	return (1);
}

int	exec_rb(t_pusha *stacks)
{
	if (!stacks->b_stack)
		return (0);
	stacks->b_stack = stacks->b_stack->next;
	if (stacks->print)
		write(1, "rb\n", 3);
	return (1);
}

int	exec_rr(t_pusha *stacks)
{
	int	ret;
	int	write_move;

	ret = 0;
	write_move = 0;
	if (stacks->print)
	{
		write_move = 1;
		stacks->print = 0;
	}
	ret = exec_ra(stacks);
	if (exec_rb(stacks) == 1)
		ret = 1;
	if (write_move)
	{
		write(1, "rr\n", 3);
		stacks->print = 1;
	}
	return (ret);
}