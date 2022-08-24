/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphasort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:11:27 by abackman          #+#    #+#             */
/*   Updated: 2022/08/24 18:58:26 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * Init both dst to 0, this will be untrue since it needs to be above 5 size
 */

static void	get_neighbor(t_stack *first, t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		max;

	tmp = first;
	min = -2147483648;
	max = 2147483647;
	while (tmp->next != first)
	{
		//ft_printf("\ninside get_neighbor\n");
		if (tmp->num >= min && tmp->num < a->num)
		{
			min = tmp->num;
			a->dst_prev = tmp;
		}
		if (tmp->num <= max && tmp->num > a->num)
		{
			max = tmp->num;
			a->dst_next = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->num >= min && tmp->num < a->num)
		a->dst_prev = tmp;
	if (tmp->num <= max && tmp->num > a->num)
		a->dst_next = tmp;
}

static void	get_destined(t_stack *a, int min, int max)
{
	t_stack *tmp;
	t_stack	*head;
	t_stack	*first;
	t_stack	*last;

	tmp = a;
	head = a;
	first = NULL;
	last = NULL;
	while (tmp->next != head)
	{
		if (tmp->num == min)
			first = tmp;
		if (tmp->num == max)
			last = tmp;
		//ft_printf("\ngetting neighbor\nhead->num :%d\n", head->num);
		get_neighbor(head, tmp);
		tmp = tmp->next;
	}
	get_neighbor(head, tmp);
	if (tmp->num == min)
		first = tmp;
	if (tmp->num == max)
		last = tmp;
	first->dst_prev = last;
	last->dst_next = first;
}

int	alphasort(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	get_destined(stacks->a_stack, stacks->min, stacks->max);
	tmp = stacks->a_stack;
	head = tmp;
	/* while (tmp->next != head)
	{
		ft_printf("\nnum: %d, next: %d, prev: %d\n", tmp->num, tmp->dst_next->num, tmp->dst_prev->num);
		tmp = tmp->next;
	}
	ft_printf("\nnum: %d, next: %d, prev: %d\n", tmp->num, tmp->dst_next->num, tmp->dst_prev->num);
 */	return (0);
}
