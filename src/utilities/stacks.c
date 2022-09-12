/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:21:02 by abackman          #+#    #+#             */
/*   Updated: 2022/09/12 15:20:39 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(t_pusha *stacks)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stacks->a_stack;
	tmp = head;
	//ft_printf("\nAre they sorted?\n");
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
	//ft_printf("\nThey are sorted\n");
	return (1);
}

int	first_stack(t_stack **head, t_stack *new)
{
	new->next = new;
	new->prev = new;
	*head = new;
	//ft_printf("\nADDING FIRST STACK\n");
	return (1);
}

int	add_stack(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*last;

	//ft_printf("Are we adding a stack?\n");
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

int	check_stacks(t_pusha *stacks)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stacks->a_stack;
	tmp = head;
	if (stacks->b_size != 0 || stacks->b_stack != NULL)
		return (free_stacks(stacks, KO));
	//ft_printf("Checking stack a: %d\nsize: %d\n\n", stacks->a_stack->num, stacks->a_size);
	while (tmp->next != head && stacks->a_size > 1)
	{
		if (tmp->num > tmp->next->num)
		{
			//ft_printf("\nnumber is larger than the next\n");
			return (free_stacks(stacks, KO));
		}
		tmp = tmp->next;
	}
	 if (tmp->num < tmp->next->num)
	 {
		//ft_printf("\nlast num is smaller than the next\n");
		return (free_stacks(stacks, KO));
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
	stacks->empty = 1;
	stacks->print = 0;
	stacks->chunk_no = 0;
	stacks->chunk_top = 0;
	stacks->chunk_bot = 0;
	return (stacks);
}