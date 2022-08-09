/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/08/09 18:03:22 by abackman         ###   ########.fr       */
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
	if (stacks->print)
		write(1, "sa\n", 3);
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
	if (stacks->print)
		write(1, "sb\n", 3);
	return (1);
}

int	exec_ss(t_pusha *stacks)
{
	int	write_move;

	write_move = 0;
	if (stacks->print)
	{
		write_move = 1;
		stacks->print = 0;
	}
	if (!exec_sa(stacks) || !exec_sb(stacks))
	{
		if (write_move)
			stacks->print = 1;
		return (0);
	}
	if (write_move)
	{
		write(1, "ss\n", 3);
		stacks->print = 1;
	}
	return (1);
}

/*
** exec_pa takes out a node from the circular double linked list of the b_stack
** and inserts it at the top of the the a_stack
*/

int	exec_pa(t_pusha *stacks)
{
	t_stack	*tmp;
	int		nullify;

	tmp = stacks->b_stack;
	nullify = 0;
	if (stacks->b_stack == NULL)
		return (0);
	if (stacks->b_stack->next == stacks->b_stack)
		nullify = 1;
	stacks->b_stack = stacks->b_stack->next;
	stacks->b_stack->prev = tmp->prev;
	stacks->b_stack->prev->next = stacks->b_stack;
	if (stacks->a_stack == NULL)
		add_to_empty(stacks->a_stack, tmp);
	else
	{
		add_head(stacks->a_stack, tmp);
		/* stacks->a_stack->prev->next = tmp;
		tmp->prev = stacks->a_stack->prev;
		stacks->a_stack->top = 0;
		tmp->next = stacks->a_stack;
		stacks->a_stack->prev = tmp; */
	}
	stacks->a_stack = tmp;
	stacks->b_size--;
	stacks->a_size++;
	stacks->b_stack->top = 1;
	/* ft_printf("\nchecking whether pb works..\na:%12d top: %d\n", stacks->a_stack->num, stacks->a_stack->top);
	ft_printf("a->next:%6d\n", stacks->a_stack->next->num);
	ft_printf("b: %11d\nb->next: %5d\n\n", stacks->b_stack->num, stacks->b_stack->next->num); */
	if (nullify)
		stacks->b_stack = NULL;
	if (stacks->print)
		write(1, "pa\n", 3);
	return (1);
}

/*
** exec_pb takes out a node from the circular double linked list of the a_stack
** and inserts it at the top of the b_stack
*/


int	exec_pb(t_pusha *stacks)
{
	t_stack	*tmp;
	int		nullify;

	tmp = stacks->a_stack;
	nullify = 0;
	if (stacks->a_stack == NULL)
		return (0);
	if (stacks->a_stack->next == stacks->a_stack)
		nullify = 1;
	stacks->a_stack = stacks->a_stack->next;
	stacks->a_stack->prev = tmp->prev;
	stacks->a_stack->prev->next = stacks->a_stack;
	if (stacks->b_stack == NULL)
		add_to_empty(stacks->b_stack, tmp);
	else
	{
		add_head(stacks->b_stack, tmp);
		/* stacks->b_stack->prev->next = tmp;
		tmp->prev = stacks->b_stack->prev;
		stacks->b_stack->top = 0;
		tmp->next = stacks->b_stack;
		stacks->b_stack->prev = tmp; */
	}
	stacks->b_stack = tmp;
	stacks->a_size--;
	stacks->b_size++;
	stacks->a_stack->top = 1;
	/* ft_printf("\nchecking whether pb works..\na:%12d top: %d\n", stacks->a_stack->num, stacks->a_stack->top);
	ft_printf("a->next:%6d\n", stacks->a_stack->next->num);
	ft_printf("b: %11d\n\n", stacks->b_stack->num); */
	 if (nullify)
		stacks->a_stack = NULL;
	if (stacks->print)
		write(1, "pb\n", 3);
	return (1);
}
