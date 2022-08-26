/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:05:05 by abackman          #+#    #+#             */
/*   Updated: 2022/08/26 19:26:01 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_rotate(t_pusha *stacks, int min, int max)
{
	t_stack	*front;
	t_stack	*back;
	
	front = stacks->a_stack;
	back = stacks->a_stack;
	while (front->next != back && back->prev != front)
	{
		if ((front->num >= min && front->num <= max) \
		|| (back->num >= min && back->num <= max) || (front == back))
			break ;
		front = front->next;
		back = back->prev;
	}
	if (front->num >= min && front->num <= max)
	{
		if (back->num >= min && back->num <= max && back->num < front->num)
			return (rotate_before_push(stacks, back->num, -1));
		else
			return (rotate_before_push(stacks, front->num, 1));
	}
	else
		return (rotate_before_push(stacks, back->num, -1));
}

 /*
 ******************** Beware of overrun, like the desired one is still in b?
 */

static void	find_minmax(t_stack *stack, int min, int max, int size)
{
	t_stack	*tmp;
	t_stack	*save;

	tmp = stack;
	save = NULL;
	min = 2147483647;
	ft_printf("\nfind_minmax: \n");
	while (tmp->next != stack)
	{
		if (tmp->num <= min)
		{
			min = tmp->num;
			save = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->num <= min)
	{
		min = tmp->num;
		save = tmp;
	}
	max = 0;
	while (++max <= size)
		save = save->dst_next;
	max = save->num;
}

static void	one_chunk(t_pusha *stacks, int size)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = stacks->min;
	max = stacks->max;
	while (++i <= size)
	{
		find_minmax(stacks->a_stack, min, max, size);
		ft_printf("\nin one_chunk\n");
		find_rotate(stacks, min, max);
		exec_pb(stacks);
	}
}

/*
** push_chunks finds the optimal moves to push chunks of similar size to
** b_stack, the count argument lets you specify the desired number of chunks.
*/

int	push_chunks(t_pusha *stacks, int count)
{
	int	i;
	int	size;

	i = 0;
	size = stacks->a_size / count;
	while (++i <= count)
	{
		print_stacks(stacks);
		//ft_printf("\nin push_chunks\n");
		if (i == count)
			size = stacks->a_size;
		one_chunk(stacks, size);
	}
	print_stacks(stacks);
	return (0);
}
