/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:28 by abackman          #+#    #+#             */
/*   Updated: 2022/08/03 16:59:55 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_ra(t_pusha *stacks)
{
	if (!stacks->a_stack)
		return (0);
	stacks->a_stack->top = 0;
	stacks->a_stack = stacks->a_stack->next;
	stacks->a_stack->top = 1;
	return (1);
}

int	exec_rb(t_pusha *stacks)
{
	if (!stacks->b_stack)
		return (0);
	stacks->b_stack->top = 0;
	stacks->b_stack = stacks->b_stack->next;
	stacks->b_stack->top = 1;
	return (1);
}

int	exec_rr(t_pusha *stacks)
{
	int	ret;

	ret = 0;
	ret = exec_ra(stacks);
	if (exec_rb(stacks) == 1)
		ret = 1;
	return (ret);
}