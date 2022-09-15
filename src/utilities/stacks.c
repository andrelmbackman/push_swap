/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:21:02 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 15:46:11 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Adds *new to the circular doubly-linked list of **head.
*/

static int	first_stack(t_stack **head, t_stack *new)
{
	new->next = new;
	new->prev = new;
	*head = new;
	return (1);
}

/*
** Returns 1 if all the numbers are sorted and in a_stack, 0 if not.
*/

int	sorted(t_pusha *stacks)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stacks->a_stack;
	tmp = head;
	if (stacks->b_size != 0 || stacks->b_stack != NULL)
		return (0);
	while (tmp->next != head && stacks->a_size > 1)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->num < tmp->next->num)
		return (0);
	return (1);
}

/*
** Creates a new node at the top of the stack with value as it's number.
*/

int	add_stack(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = value;
	new->chunk = 0;
	if (*head == NULL)
		return (first_stack(head, new));
	last = (*head)->prev;
	last->next = new;
	new->prev = last;
	new->next = (*head);
	(*head)->prev = new;
	new->dst_next = NULL;
	new->dst_prev = NULL;
	return (1);
}

/*
** Checks the state of the stacks and calls a function to free them.
*/

int	check_stacks(t_pusha *stacks)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stacks->a_stack;
	tmp = head;
	if (stacks->b_size != 0 || stacks->b_stack != NULL)
		return (free_stacks(stacks, KO));
	while (tmp->next != head && stacks->a_size > 1)
	{
		if (tmp->num > tmp->next->num)
			return (free_stacks(stacks, KO));
		tmp = tmp->next;
	}
	if (tmp->num < tmp->next->num)
		return (free_stacks(stacks, KO));
	return (free_stacks(stacks, OK));
}

/*
** Initializes the main struct, allocating space for it and initializing it's
** variables and then returning it.
*/

t_pusha	*init_stacks(void)
{
	t_pusha	*stacks;

	stacks = (t_pusha *)malloc(sizeof(t_pusha));
	if (stacks == NULL)
		return (NULL);
	stacks->a_stack = NULL;
	stacks->b_stack = NULL;
	stacks->valid_moves = NULL;
	stacks->min = 0;
	stacks->max = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->empty = 1;
	stacks->print = 0;
	stacks->v = 0;
	stacks->chunk_no = 12;
	stacks->chunk_top = 0;
	stacks->chunk_bot = 0;
	return (stacks);
}
