/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_subchunks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:01:13 by abackman          #+#    #+#             */
/*   Updated: 2022/09/01 15:21:08 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	one_node(t_pusha *stacks, int min, int max)
{

}

static void	one_subchunk(t_pusha *stacks, int cur, int size)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = stacks->min;
	max = stacks->max;
}

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
	int		cur;

	cur = -1;
	while (++cur < count)
	{
		one_chunk(stacks, count - cur);
	}
	return (1);
}