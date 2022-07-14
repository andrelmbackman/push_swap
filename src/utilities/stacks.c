/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:21:02 by abackman          #+#    #+#             */
/*   Updated: 2022/07/14 18:22:12 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_stacks(t_pusha *stacks, int status)
{
	t_stack	*tmp;
	t_stack	*head;

	head = stacks->a_stack->next;
	while (head != stacks->a_stack)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
	head = stacks->b_stack->next;
	while (head != stacks->b_stack)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
	free(stacks);
	stacks = NULL;
	//system("leaks checker");
	return (return_status(status));
}

static int	first_stack(t_stack **head, t_stack *new)
{
	new->top = 1;
	new->next = new;
	new->prev = new;
	*head = new;
	return (1);
}

int	add_stack(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*last;

	//ft_printf("\nadd_stack\n");
	last = (*head)->prev;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = value;
	if (*head == NULL)
		return (first_stack(head, new));
	new->next = *head;
	(*head)->prev = new;
	new->top = 0;
	new->prev = last;
	last->next = new;
	return (1);
}

int	check_stacks(t_pusha *stacks)
{
	t_stack	*head;

	head = stacks->a_stack;
	if (stacks->b_size != 0)
		return (free_stacks(stacks, KO));
	ft_printf("Checking stack a: %d\n", stacks->a_stack->num);
	while (stacks->a_stack->next != NULL)
	{
		if (stacks->a_stack->next->num < stacks->a_stack->num)
			return (free_stacks(stacks, KO));
		stacks->a_stack = stacks->a_stack->next;
	}
	return (free_stacks(stacks, OK));
}

t_pusha	*init_stacks(void)
{
	t_pusha	*stacks;

	stacks = (t_pusha *)malloc(sizeof(t_pusha));
	if (stacks == NULL)
		return (NULL);
	stacks->a_stack = NULL;
	stacks->b_stack = NULL;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->min = 0;
	stacks->max = 0;
	return (stacks);
}