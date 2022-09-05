/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_subchunks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:01:13 by abackman          #+#    #+#             */
/*   Updated: 2022/09/05 13:20:39 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_chunksize(t_stack *a, int count)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	if (tmp == NULL)
		return (0);
	while (tmp->next != a)
	{
		if (tmp->chunk == count)
			i++;
		tmp = tmp->next;
	}
	if (tmp->chunk == count)
			i++;
	return (i);
}

static void	minmax_subchunk(t_stack *stack, int min, int max, int cur)
{
	t_stack	*tmp;

	tmp = stack;
	if (!stack)
		return ;
	while (tmp->next != stack)
	{
		if (stack->chunk == cur)
		{
			if (stack->num >= max)
				max = stack->num;
			if (stack->num <= min)
				min = stack->num;
		}
		tmp = tmp->next;
	}
	if (stack->chunk == cur)
	{
		if (stack->num >= max)
			max = stack->num;
		if (stack->num <= min)
			min = stack->num;
	}
}

static void	one_subchunk(t_pusha *stacks, int cur, int size)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = stacks->max;
	max = stacks->min;
	minmax_subchunk(stacks->b_stack, min, max, cur);
	while (++i <= size)
	{
		one_node(stacks, min, max);
	}
}


static void	one_chunk(t_pusha *stacks, int cur)
{
	int	sub_max;
	int	sub_cur;
	int	size;
	
	sub_max = 4;
	sub_cur = 1;
	size = get_chunksize(stacks->b_stack, cur) / sub_max;
	while (sub_cur <= sub_max)
	{
		if (sub_cur == sub_max)
			size = get_chunksize(stacks->b_stack, cur);
		one_subchunk(stacks, cur, size);
		sub_cur++;
	}
}

int	pushback_subchunks(t_pusha *stacks, int count)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		one_chunk(stacks, count - i);
	}
	return (1);
}