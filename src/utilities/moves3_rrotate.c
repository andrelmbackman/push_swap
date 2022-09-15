/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:38 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 15:35:25 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Rotates the b_stack so that the last node will become the first. If called
** by push_swap it will write the command to stdout.
*/

int	exec_rra(t_pusha *stacks)
{
	if (!stacks->a_stack)
		return (0);
	stacks->a_stack = stacks->a_stack->prev;
	if (stacks->print == 1)
		write(1, "rra\n", 4);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

/*
** Rotates the b_stack so that the last node will become the first. If called
** by push_swap it will write the command to stdout.
*/

int	exec_rrb(t_pusha *stacks)
{
	if (!stacks->b_stack)
		return (0);
	stacks->b_stack = stacks->b_stack->prev;
	if (stacks->print == 1)
		write(1, "rrb\n", 4);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

/*
** Rotates both stacks so that the last node will become the first. If called
** by push_swap it will write the command to stdout.
*/

int	exec_rrr(t_pusha *stacks)
{
	int	ret;

	ret = 0;
	if (stacks->print)
		stacks->print = 2;
	if (stacks->v)
		stacks->v = 2;
	ret = exec_ra(stacks);
	if (exec_rb(stacks) == 1)
		ret = 1;
	if (stacks->print == 2)
	{
		write(1, "rrr\n", 4);
		stacks->print = 1;
	}
	if (stacks->v)
	{
		print_stacks(stacks);
		stacks->v = 1;
	}
	return (ret);
}
