/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/07/14 19:57:13 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_sa(t_pusha *stacks)
{
	int	tmp;

	if ((stacks->a_size < 2) || (stacks->a_stack->next == NULL))
		return (0);
	tmp = stacks->a_stack->num;
	stacks->a_stack->num = stacks->a_stack->next->num;
	stacks->a_stack->next->num = tmp;
	return (1);
}

int	exec_sb(t_pusha *stacks)
{
	int	tmp;

	if ((stacks->b_size) < 2 || (stacks->b_stack->next == NULL))
		return (0);
	tmp = stacks->b_stack->num;
	stacks->b_stack->num = stacks->b_stack->next->num;
	stacks->b_stack->next->num = tmp;
	return (1);
}

int	exec_ss(t_pusha *stacks)
{
	if (!exec_sa(stacks))
		return (0);
	if (!exec_sb(stacks))
		return (0);
	return (1);
}

/*
** exec_pa takes out a node from the circular double linked list of the b_stack
** and inserts it into the a_stack
*/

int	exec_pa(t_pusha *stacks)
{
	t_stack	*tmp;
	if ((stacks->b_stack == NULL) || (stacks->b_size = 0))
		return (0);
	tmp = stacks->b_stack;
	stacks->b_stack->next->top = 1;
	stacks->b_stack->next->prev = stacks->b_stack->prev;
	stacks->b_stack->prev->next = stacks->b_stack->next;
	stacks->b_size--;
	stacks->a_stack->prev->next = tmp;
	tmp->prev = stacks->a_stack->prev;
	stacks->a_stack->top = 0;
	stacks->a_stack->prev = tmp;
	tmp->next = stacks->a_stack;
	return (1);
}

int	exec_pb(t_pusha *stacks)
{
	return (1);
}