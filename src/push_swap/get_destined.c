/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_destined.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:11:10 by abackman          #+#    #+#             */
/*   Updated: 2022/08/30 13:52:28 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * Init both dst to 0, this will be untrue since it needs to be above 5 size
 */
/* typedef struct	s_chunk
{
	int				min;
	int				max;
	int				size;
	t_stack			*first;
	t_stack			*last;
	struct s_chunk	*next;
	struct s_chunk	*prev;
}	t_chunk;
 */
static void	get_chunk_no(t_stack *first, int size)
{
	t_stack	*tmp;
	int		x;
	int		chunk_no;
	int		count;

	x = 0;
	chunk_no = 1;
	tmp = first;
	if (size <= 100)
		count = 2;
	else
		count = 4;
	while (tmp->dst_next != first)
	{
		x = 0;
		while (++x <= size / count && tmp->dst_next != first)
		{
			tmp->chunk = chunk_no;
			//ft_printf("get_chunk_no -  num: %d chunk: %d\n", tmp->num, tmp->chunk);
			tmp = tmp->dst_next;
		}
		if (chunk_no < count)
			chunk_no++;
	}
	tmp->chunk = chunk_no;
	//ft_printf("get_chunk_no -  num: %d chunk: %d\n", tmp->num, tmp->chunk);
}

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

void	get_destined(t_stack *a, int min, int max, int size)
{
	t_stack *tmp;
	t_stack	*first;
	t_stack	*last;

	tmp = a;
	first = NULL;
	last = NULL;
	while (tmp->next != a)
	{
		if (tmp->num == min)
			first = tmp;
		if (tmp->num == max)
			last = tmp;
		get_neighbor(a, tmp);
		tmp = tmp->next;
	}
	get_neighbor(a, tmp);
	if (tmp->num == min)
		first = tmp;
	if (tmp->num == max)
		last = tmp;
	first->dst_prev = last;
	last->dst_next = first;
	get_chunk_no(first, size);
	/* t_stack	*test = a;
	while (test->next != a)
	{
		ft_printf("\nnum: %d prev: %d next: %d\ndst_prev: %d dst_next: %d\n", \
		test->num, test->prev->num, test->next->num, test->dst_prev->num, test->dst_next->num);
		test = test->next;
	}
	ft_printf("\nnum: %d prev: %d next: %d\ndst_prev: %d dst_next: %d\n", \
		test->num, test->prev->num, test->next->num, test->dst_prev->num, test->dst_next->num); */
}
