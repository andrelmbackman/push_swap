/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:05:05 by abackman          #+#    #+#             */
/*   Updated: 2022/08/31 19:59:05 by abackman         ###   ########.fr       */
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

static void	final_rotate(t_pusha *stacks)
{
	t_stack	*tmp;
	int		i;

	tmp = stacks->a_stack;
	i = 0;
	while (tmp->next != stacks->a_stack)
	{
		if (tmp->num == stacks->min)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < (stacks->a_size / 2))
	{
		while (!sorted(stacks))
			exec_ra(stacks);
	}
	else
	{
		while (!sorted(stacks))
			exec_rra(stacks);
	}
}
/*
** This find_rotate is used with two_chunks, the functions used for one_chunk
** can be found above.
*/

static int	find_rotate(t_pusha *stacks, int chunk, int max)
{
	t_stack	*front;
	t_stack	*back;

	front = stacks->a_stack;
	back = stacks->a_stack;
	while (front->next != back && back->prev != front)
	{
		if (front->chunk == chunk || front->chunk == (max - chunk) \
		|| back->chunk == chunk || back->chunk == (max - chunk))
			break ;
		front = front->next;
		back = back->prev;
		if (front == back)
			break ;
	}
	//ft_printf("\nfind_rotate\nchunk: %d frontchunk: %d backchunk: %d", chunk, front->chunk, back->chunk);
	if (front->chunk == chunk || front->chunk == (max - chunk))
	{
		if ((back->chunk == chunk || back->chunk == (max - chunk)) && \
		back->num < front->num)
			return (rotate_before_push(stacks, back->num, -1));
		else
			return (rotate_before_push(stacks, front->num, 1));
	}
	else
		return (rotate_before_push(stacks, back->num, -1));
}

/* static void	two_chunks(t_pusha *stacks, int size, int count, int max)
{
	int	i;
	int	chunk;

	i = -1;
	chunk = max - count;
	if (chunk == 2)
		chunk *= 2;
	while (++i < (size * 2))
	{
		if (stacks->a_stack == NULL)
			break ;
		//ft_printf("\ntwo_chunks\n");
		find_rotate(stacks, chunk);
		exec_pb(stacks);
		if (stacks->b_stack->chunk != chunk)
		{
			if (stacks->a_stack->chunk != chunk && stacks->a_stack->chunk != \
			(5 - chunk))
				exec_rr(stacks);
			else
				exec_rb(stacks);
		}
	}
} */

/* static void	two_chunks(t_pusha *stacks, int size, int count, int max)
{
	int	i;

	i = -1;
	while (++i <= (size * 2))
	{
		if (stacks->a_stack == NULL)
			break ;
		//ft_printf("\ntwo_chunks\n");
		find_rotate(stacks, count, max);
		exec_pb(stacks);
		if (stacks->b_stack->chunk == count)
		{
			if (stacks->a_stack->chunk != count && stacks->a_stack->chunk != \
			(max - count))
				exec_rr(stacks);
			else
				exec_rb(stacks);
		}
	}
} */

static int	stacks_left(t_stack *a, int chunk1, int chunk2)
{
	t_stack	*tmp;
	int		ret;

	tmp = a;
	ret = 0;
	if (a == NULL)
		return (0);
	while (tmp->next != a)
	{
		if (tmp->chunk == chunk1 || tmp->chunk == chunk2)
			ret = 1;
		tmp = tmp->next;
	}
	if (tmp->chunk == chunk1 || tmp->chunk == chunk2)
			ret = 1;
	/* if (ret == 0)
		ft_printf("\nno stacks left >> %d %d", chunk1, chunk2); */
	return (ret);
}

static void	two_chunks(t_pusha *stacks, int size, int cur, int max)
{
	int	i;

	i = 0;
	if (size)
		i = -1;
	while (stacks_left(stacks->a_stack, cur, max - cur))
	{
		if (stacks->a_stack == NULL)
			break ;
		//ft_printf("\ntwo_chunks\n");
		find_rotate(stacks, cur, max);
		exec_pb(stacks);
		if (stacks->b_stack->chunk == cur)
		{
			if (stacks->a_stack)
			{
				if (stacks->a_stack->chunk != cur && stacks->a_stack->chunk != \
				(max - cur))
					exec_rr(stacks);
				else
					exec_rb(stacks);
			}
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
	int	cur;
	int	size;

	cur = (count / 2) + 1;
	size = stacks->a_size / count;
	if (count % 2 == 0)
		count++;
	//stacks->print = 0;
	while (--cur >= 1)
	{
		//print_stacks(stacks);
		//ft_printf("\ncur: %d other: %d\n", cur, count - cur);
		if (stacks->a_stack == NULL)
			break ;
		if (cur == 1)
			size = stacks->a_size;
		//ft_printf("\nin push_chunks\ni: %d size: %d count: %d\n", i, size, count);
		//one_chunk(stacks, size);
		two_chunks(stacks, size, cur, count);
	}
	//print_stacks(stacks);
	while (stacks->a_stack != NULL)
		exec_pb(stacks);
	rotate_pushback(stacks);
	//print_stacks(stacks);
	if (!sorted(stacks))
		final_rotate(stacks);
	//print_stacks(stacks);
	return (0);
}
