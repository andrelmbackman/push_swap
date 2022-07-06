/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:21:02 by abackman          #+#    #+#             */
/*   Updated: 2022/07/06 18:42:00 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_stacks(t_pusha *stacks, int status)
{
	t_stack	*tmp;

	while (stacks->a_stack)
	{
		tmp = stacks->a_stack->next;
		free(stacks->a_stack);
		stacks->a_stack = NULL;
		stacks->a_stack = tmp;
	}
	while (stacks->b_stack)
	{
		tmp = stacks->b_stack->next;
		free(stacks->b_stack);
		stacks->b_stack = NULL;
		stacks->b_stack = tmp;
	}
	free(stacks);
	stacks = NULL;
	return (return_status(status));
}

t_stack	*add_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = value;
	new->next = NULL;
	return (new);
}

int	check_stacks(t_pusha *stacks)
{
	t_stack	*head;

	head = stacks->a_stack;
	if (stacks->b_size != 0)
		return (free_stacks(stacks, KO));
	while (stacks->a_stack != NULL)
	{
		if (stacks->a_stack->next->num < stacks->a_stack->num && \
		stacks->a_stack->next != NULL)
			return (free_stacks(stacks, KO));
		stacks->a_stack = stacks->a_stack->next;
	}
	return (free_stacks(stacks, OK));
}