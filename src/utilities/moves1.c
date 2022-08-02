/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/08/02 19:02:54 by abackman         ###   ########.fr       */
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
	if (!exec_sa(stacks) || !exec_sb(stacks))
		return (0);
	return (1);
}

/*
** exec_pa takes out a node from the circular double linked list of the b_stack
** and inserts it at the top of the the a_stack
*/

int	exec_pa(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((stacks->b_stack == NULL) || (stacks->b_size = 0))
		return (0);
	tmp = stacks->b_stack;
	head = stacks->b_stack->next;
	head->top = 1;
	stacks->b_stack->next->prev = stacks->b_stack->prev;
	stacks->b_stack->prev->next = stacks->b_stack->next;
	stacks->b_size--;
	stacks->b_stack = head;
	stacks->a_stack->prev->next = tmp;
	tmp->prev = stacks->a_stack->prev;
	stacks->a_stack->top = 0;
	stacks->a_stack->prev = tmp;
	tmp->next = stacks->a_stack;
	stacks->a_stack = tmp;
	return (1);
}

/*
** exec_pb takes out a node from the circular double linked list of the a_stack
** and inserts it at the top of the b_stack
*/

int	exec_pb(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((stacks->a_stack == NULL) || (stacks->a_size = 0))
		return (0);
	if ((stacks->b_stack == NULL) || (stacks->b_size = 0))
		first_stack(&stacks->b_stack, stacks->a_stack);
	else
	{
		//ft_printf("\nPB: b_stack not empty\n");
		tmp = stacks->a_stack;
		stacks->b_stack->prev->next = tmp;
		tmp->prev = stacks->b_stack->prev;
		stacks->b_stack->prev = tmp;
		tmp->next = stacks->b_stack;
		stacks->b_stack->top = 0;
		stacks->b_stack = tmp;
	}
	stacks->a_size--;
	head = stacks->a_stack;
	stacks->a_stack = stacks->a_stack->next;
	stacks->a_stack->prev = head->prev;
	stacks->a_stack->prev->next = stacks->a_stack;
	stacks->a_stack->top = 1;
	ft_printf("\nchecking whether pb works..\na:%d b:%d\n\n", \
	stacks->a_stack->next->next->num, stacks->b_stack->num);
	return (1);
}

/* int	exec_pb(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((stacks->a_stack == NULL) || (stacks->a_size = 0))
		return (0);
	if ((stacks->b_stack == NULL) || (stacks->b_size = 0))
		first_stack(&stacks->b_stack, stacks->a_stack);
	else
	{
		
	}
	tmp = stacks->a_stack;
	head = stacks->a_stack->next;
	head->top = 1;
	stacks->a_stack->next->prev = stacks->a_stack->prev;
	stacks->a_stack->prev->next = stacks->a_stack->next;
	stacks->a_size--;
	stacks->b_stack->prev->next = tmp;
	tmp->prev = stacks->b_stack->prev;
	stacks->b_stack->top = 0;
	stacks->b_stack->prev = tmp;
	tmp->next = stacks->b_stack;
	stacks->b_stack = tmp;
	return (1);
} */