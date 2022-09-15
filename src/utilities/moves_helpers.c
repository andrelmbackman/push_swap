/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:14:55 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 15:26:29 by abackman         ###   ########.fr       */
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
	new->next = stack;
	stack->prev = new;
	if (new->next == new)
		new = NULL;
}

/*
** Adds the *new node to the empty *stack. If it was the last node of the *new
** list, it is pointed to NULL.
*/

void	add_to_empty(t_stack *stack, t_stack *new)
{
	stack = new;
	stack->next = stack;
	stack->prev = stack;
	if (new->next == new)
		new = NULL;
}
