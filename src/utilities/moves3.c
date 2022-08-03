/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:38 by abackman          #+#    #+#             */
/*   Updated: 2022/08/03 17:05:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_rra(t_pusha *stacks)
{
	if (!stacks->a_stack)
		return (0);
	stacks->a_stack->top = 0;
	stacks->a_stack = stacks->a_stack->prev;
	stacks->a_stack->top = 1;
	return (1);
}

int	exec_rrb(t_pusha *stacks)
{
	if (!stacks->b_stack)
		return (0);
	stacks->b_stack->top = 0;
	stacks->b_stack = stacks->b_stack->prev;
	stacks->b_stack->top = 1;
	return (1);
}

int	exec_rrr(t_pusha *stacks)
{
	int	ret;

	ret = 0;
	ret = exec_ra(stacks);
	if (exec_rb(stacks) == 1)
		ret = 1;
	return (1);
}
