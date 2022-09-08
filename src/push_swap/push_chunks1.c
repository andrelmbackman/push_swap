/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:05:05 by abackman          #+#    #+#             */
/*   Updated: 2022/09/08 14:57:18 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	final_rotate(t_pusha *stacks)
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

/* static int	find_rotate(t_pusha *stacks, int chunk, int max)
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
} */


/* static int	stacks_left(t_stack *a, int chunk1, int chunk2)
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
	if (ret == 0)
		ft_printf("\nno stacks left >> %d %d", chunk1, chunk2);
	return (ret);
}
 */
/* static void	two_chunks(t_pusha *stacks, int size, int cur, int max)
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
} */

/*
** push_chunks finds the optimal moves to push chunks of similar size to
** b_stack, the count argument lets you specify the desired number of chunks.
*/
/* 
int	push_chunks(t_pusha *stacks, int count)
{
	int	cur;
	int	size;

	cur = (count / 2) + 1;
	size = stacks->a_size / count;
	if (count % 2 == 0)
		count++;
	stacks->print = 0;
	while (--cur >= 1)
	{
		//print_stacks(stacks);
		ft_printf("\ncur: %d other: %d\n", cur, count - cur);
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
} */
static int	size_4_chunks(t_pusha *stacks)
{
	int		ret;
	t_stack	*tmp;

	ret = 0;
	tmp = stacks->a_stack;
	if (tmp == NULL)
		return (0);
	while (tmp->next != stacks->a_stack)
	{
		if (tmp->chunk >= stacks->chunk_bot && tmp->chunk <= stacks->chunk_top)
			ret++;
		tmp = tmp->next;
	}
	if (tmp->chunk >= stacks->chunk_bot && tmp->chunk <= stacks->chunk_top)
		ret++;
	return (ret);
}

static void	check_rotate(t_stack *a, t_stack *b, t_pusha *s)
{
	if (a == NULL)
	{
		if (b->chunk == (s->chunk_bot + 1) || b->chunk == (s->chunk_top - 1))
			exec_rb(s);
		return ;
	}
	if (b == NULL)
	{
		if (a->chunk < s->chunk_bot || a->chunk > s->chunk_top)
			exec_ra(s);
		return ;
	}
	if (a->chunk < s->chunk_bot || a->chunk > s->chunk_top)
	{
		if (b->chunk == (s->chunk_bot + 1) || b->chunk == (s->chunk_top - 1))
			exec_rr(s);
		else
			exec_ra(s);
	}
	else if (b->chunk == (s->chunk_bot + 1) || b->chunk == (s->chunk_top - 1))
			exec_rb(s);
}

static void	push_4_chunks(t_pusha *stacks, int size, int min, int max)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stacks->a_stack->chunk >= min && stacks->a_stack->chunk <= max)
		{
			exec_pb(stacks);
			i++;
		}
		check_rotate(stacks->a_stack, stacks->b_stack, stacks);
	}
}

int	push_chunks(t_pusha *stacks, int count)
{
	int	size;

	size = size_4_chunks(stacks);
	while (stacks->a_stack != NULL && stacks->chunk_top <= count)
	{
		push_4_chunks(stacks, size, stacks->chunk_bot, stacks->chunk_top);
		stacks->chunk_bot -= 2;
		stacks->chunk_top += 2;
		size = size_4_chunks(stacks);
		//print_stacks(stacks);
	}
	rotate_pushback(stacks);
	final_rotate(stacks);
	return (1);
}