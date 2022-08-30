/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:05:05 by abackman          #+#    #+#             */
/*   Updated: 2022/08/30 16:36:57 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* static int	find_rotate(t_pusha *stacks, int min, int max)
{
	t_stack	*front;
	t_stack	*back;
	
	front = stacks->a_stack;
	back = stacks->a_stack;
	while (front->next != back && back->prev != front)
	{
		if ((front->num >= min && front->num <= max) \
		|| (back->num >= min && back->num <= max))
			break ;
		front = front->next;
		back = back->prev;
		if (front == back)
			break ;
	}
	//ft_printf("\n{red}front: %d back: %d{eoc}\n", front->num, back->num);
	if (front->num >= min && front->num <= max)
	{
		if (back->num >= min && back->num <= max && back->num < front->num)
			return (rotate_before_push(stacks, back->num, -1));
		else
			return (rotate_before_push(stacks, front->num, 1));
	}
	else
		return (rotate_before_push(stacks, back->num, -1));
} */

 /*
 ******************** Beware of overrun, like the desired one is still in b?
 */
/* 
static void	find_minmax(t_stack *stack, int *min, int *max, int size)
{
	t_stack	*tmp;
	t_stack	*save;

	tmp = stack;
	save = NULL;
	*min = 2147483647;
	//ft_printf("\nfind_minmax: \n");
	while (tmp->next != stack)
	{
		if (tmp->num <= *min)
		{
			*min = tmp->num;
			save = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->num <= *min)
	{
		*min = tmp->num;
		save = tmp;
	}
	*max = 0;
	while (++*max < size)
		save = save->dst_next;
	*max = save->num;
}

static void	one_chunk(t_pusha *stacks, int size)
{
	//int	i;
	int	min;
	int	max;

	//i = 0;
	min = stacks->min;
	max = stacks->max;
	while (size > 0)
	{
		if (stacks->a_stack == NULL)
			break ;
		find_minmax(stacks->a_stack, &min, &max, size);
		//ft_printf("\nin one_chunk - min: %d max: %d size: %d\n", min, max, size);
		find_rotate(stacks, min, max);
		exec_pb(stacks);
		size--;
	}
} */


/*
** This find_rotate is used with two_chunks, the functions used for one_chunk
** can be found above.
*/

static int	find_rotate(t_pusha *stacks, int chunk)
{
	t_stack	*front;
	t_stack	*back;

	front = stacks->a_stack;
	back = stacks->a_stack;
	while (front->next != back && back->prev != front)
	{
		if (front->chunk == chunk || front->chunk == (5 - chunk) \
		|| back->chunk == chunk || back->chunk == (5 - chunk))
			break ;
		front = front->next;
		back = back->prev;
		if (front == back)
			break ;
	}
	//ft_printf("\nfind_rotate\nchunk: %d frontchunk: %d backchunk: %d", chunk, front->chunk, back->chunk);
	if (front->chunk == chunk || front->chunk == (5 - chunk))
	{
		if ((back->chunk == chunk || back->chunk == (5 - chunk)) && \
		back->num < front->num)
			return (rotate_before_push(stacks, back->num, -1));
		else
			return (rotate_before_push(stacks, front->num, 1));
	}
	else
		return (rotate_before_push(stacks, back->num, -1));
}

static void	two_chunks(t_pusha *stacks, int size, int count)
{
	int	i;

	i = 0;
	size = 90;
	while (++i <= count)
	{
		//ft_printf("\ntwo_chunks\n");
		find_rotate(stacks, count);
		exec_pb(stacks);
		if (stacks->b_stack->chunk == (5 - count))
		{
			if (stacks->a_stack->chunk != count && stacks->a_stack->chunk != \
			(5 - count))
				exec_rr(stacks);
			else
				exec_rb(stacks);
		}
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
		if (stacks->a_stack == NULL)
			break ;
		if (i == count)
			size = stacks->a_size;
		//ft_printf("\nin push_chunks\ni: %d size: %d count: %d\n", i, size, count);
		//one_chunk(stacks, size);
		two_chunks(stacks, size, i);
	}
	//print_stacks(stacks);
	rotate_pushback(stacks);
	while (!sorted(stacks))
		exec_rra(stacks);
	//print_stacks(stacks);
	return (0);
}
