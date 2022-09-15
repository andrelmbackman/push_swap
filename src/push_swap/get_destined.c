/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_destined.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:11:10 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 14:01:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Assigns a chunk number in ascending order to each node of t_stack *first.
** Size is the size of the stack and chunks is the number of chunks it should
** be divided into.
*/

static void	get_chunks(t_stack *first, int size, int chunks)
{
	t_stack	*tmp;
	int		x;
	int		chunk_no;
	int		count;

	x = 0;
	chunk_no = 1;
	tmp = first;
	count = chunks;
	while (tmp->dst_next != first)
	{
		x = 0;
		while (++x <= size / count && tmp->dst_next != first)
		{
			tmp->chunk = chunk_no;
			tmp = tmp->dst_next;
		}
		if (chunk_no < count)
			chunk_no++;
	}
	tmp->chunk = chunk_no;
}

/*
** Iterates through the t_stack list, in the order it was given, to find which
** node should come before (dst_prev) and after (dst_next) when sorted.
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
		if (tmp->num >= min && tmp->num < a->num)
		{
			min = tmp->num;
			a->dst_prev = tmp;
		}
		else if (tmp->num <= max && tmp->num > a->num)
		{
			max = tmp->num;
			a->dst_next = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->num >= min && tmp->num < a->num)
		a->dst_prev = tmp;
	else if (tmp->num <= max && tmp->num > a->num)
		a->dst_next = tmp;
}

/*
** Iterates through the a_stack and finds the destined prev and next pointers
** of each node. If the number of ints given is 24 or larger, the stack will
** be divided into chunks, for optimized sorting.
*/

void	get_destined(t_pusha *stacks, int min, int max, int size)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	tmp = stacks->a_stack;
	first = NULL;
	last = NULL;
	while (tmp->next != stacks->a_stack)
	{
		if (tmp->num == min)
			first = tmp;
		if (tmp->num == max)
			last = tmp;
		get_neighbor(stacks->a_stack, tmp);
		tmp = tmp->next;
	}
	get_neighbor(stacks->a_stack, tmp);
	if (tmp->num == min)
		first = tmp;
	if (tmp->num == max)
		last = tmp;
	first->dst_prev = last;
	last->dst_next = first;
	if (size > 23)
		get_chunks(first, size, stacks->chunk_no);
}
