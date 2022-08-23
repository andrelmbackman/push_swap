/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:14:55 by abackman          #+#    #+#             */
/*   Updated: 2022/08/23 17:59:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** This function adds the *new node to the head of the *stack list, if possible.
*/

void	add_head(t_stack *stack, t_stack *new)
{
	stack->prev->next = new;
	new->prev = stack->prev;
	stack->top = 0;
	new->next = stack;
	stack->prev = new;
	if (new->next == new)
		new = NULL;
}

void	add_to_empty(t_stack *stack, t_stack *new)
{
	/* t_stack	*head;

	//ft_printf("\nadding to empty,\nnum = %d\nstack = %p\n\n", new->num, stack);
	head = new;
	head->next = head;
	head->prev = head;
	stack = head; */
	stack = new;
	stack->next = stack;
	stack->prev = stack;
	if (new->next == new)
		new = NULL;
}

/*
** This function removes the head node of the list. No memory is freed, and this
** function is only used after add_head, therefore the head is not lost.
*/

/* void	rm_head(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	**head;

	head = &stack;
	if (*head == NULL)
		return ;
	if ((*head)->next == *head && (*head)->prev == *head)
		*head = NULL;
	else
	{
		ft_printf("\ntrying to rm head.\n");
		tmp = *head;
		*head = (*head)->next;
		tmp->prev->next = *head;
		(*head)->prev = tmp->prev;
		(*head)->top = 1;
		//free(tmp);
		//tmp = NULL;
	}
	ft_printf("\nrm_head, address of stack: %p\n", stack);
} */
