/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/09/13 19:35:06 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int	exec_sa(t_pusha *stacks)
{
	t_stack	*tmp;

	if (stacks->a_size < 2)
		return (0);
	tmp = stacks->a_stack;
	stacks->a_stack = stacks->a_stack->next;
	if (stacks->a_size > 2)
	{
		stacks->a_stack->prev = tmp->prev;
		stacks->a_stack->prev->next = stacks->a_stack;
		tmp->next = stacks->a_stack->next;
	}
	else
	{
		stacks->a_stack->prev = tmp;
		stacks->a_stack->prev->next = stacks->a_stack;
	}
	tmp->prev = stacks->a_stack;
	stacks->a_stack->next = tmp;
	if (stacks->print == 1)
		write(1, "sa\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
} */

/* int	exec_sb(t_pusha *stacks)
{
	t_stack	*tmp;

	if (stacks->b_size < 2)
		return (0);
	tmp = stacks->b_stack;
	stacks->b_stack = stacks->b_stack->next;
	if (stacks->b_size > 2)
	{
		stacks->b_stack->prev = tmp->prev;
		stacks->b_stack->prev->next = stacks->b_stack;
		tmp->next = stacks->b_stack->next;
	}
	else
	{
		stacks->b_stack->prev = tmp;
		stacks->b_stack->prev->next = stacks->b_stack;
	}
	tmp->prev = stacks->b_stack;
	stacks->b_stack->next = tmp;
	if (stacks->print == 1)
		write(1, "sb\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
} */

int	exec_sa(t_pusha *stacks)
{
	int	tmp;

	if (stacks->a_size < 2)
		return (0);
	tmp = stacks->a_stack->num;
	stacks->a_stack->num = stacks->a_stack->next->num;
	stacks->a_stack->next->num = tmp;
	tmp = stacks->a_stack->chunk;
	stacks->a_stack->chunk = stacks->a_stack->next->chunk;
	stacks->a_stack->next->chunk = tmp;
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
	tmp = stacks->b_stack->chunk;
	stacks->b_stack->chunk = stacks->b_stack->next->chunk;
	stacks->b_stack->next->chunk = tmp;
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
	exec_sa(stacks);
	exec_sb(stacks);
	/* if (!exec_sa(stacks) && !exec_sb(stacks))
	{
		if (stacks->print == 2)
			stacks->print = 1;
		if (stacks->v == 2)
			stacks->v = 1;
		return (0);
	} 
	else*/ if (stacks->print == 2)
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
