/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:05:05 by abackman          #+#    #+#             */
/*   Updated: 2022/10/11 15:10:26 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** After the stacks are in order, the smallest number needs to be at the top.
** final_rotate finds out which rotation would require fewer moves to achieve
** this and then rotates until the stack is sorted in ascending order.
*/

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
	if (i <= (stacks->a_size / 2))
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
** Counts how many nodes are within the chunk range chunk_bot - chunk_top.
*/

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
		if (tmp->chunk == stacks->chunk_bot || \
		tmp->chunk == stacks->chunk_bot + 1 || \
		tmp->chunk == stacks->chunk_top - 1 || \
		tmp->chunk == stacks->chunk_top)
			ret++;
		tmp = tmp->next;
	}
	if (tmp->chunk == stacks->chunk_bot || \
	tmp->chunk == stacks->chunk_bot + 1 || \
	tmp->chunk == stacks->chunk_top - 1 || \
	tmp->chunk == stacks->chunk_top)
		ret++;
	return (ret);
}

/*
** Checks whether a double move (rr) would be beneficial. For this algorithm
** to be efficient we need to push half of the chunks to the bottom, that way
** fewer moves are required when looking to push back certain numbers to a.
*/

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
		if (a->chunk > s->chunk_bot + 1 || a->chunk < s->chunk_top - 1)
			exec_ra(s);
		return ;
	}
	if (a->chunk > s->chunk_bot + 1 || a->chunk < s->chunk_top - 1)
	{
		if (b->chunk == (s->chunk_bot + 1) || b->chunk == (s->chunk_top - 1))
			exec_rr(s);
		else
			exec_ra(s);
	}
	else if (b->chunk == (s->chunk_bot + 1) || b->chunk == (s->chunk_top - 1))
		exec_rb(s);
}

/*
** Given the size of how many nodes should be pushed to b_stack, rotates
** and pushes nodes to the b_stack.
*/

static void	push_4_chunks(t_pusha *stacks, int size, int min, int max)
{
	int	i;
	int	c;

	i = 0;
	while (i < size)
	{
		c = stacks->a_stack->chunk;
		if (c == min || c == max || c == min + 1 || c == max - 1)
		{
			exec_pb(stacks);
			i++;
		}
		check_rotate(stacks->a_stack, stacks->b_stack, stacks);
	}
}

/*
** Sorts stacks that are 24 numbers or larger. Pushes 4 chunks at a time to
** b_stack, giving them an even spread but still not requiring a lot of moves.
** Sorts them back in order by finding either the smallest or largest number.
*/

int	sort_big(t_pusha *stacks, int count)
{
	int	size;

	size = size_4_chunks(stacks);
	if (!count)
		return (0);
	while (stacks->a_stack != NULL && stacks->chunk_bot < stacks->chunk_top)
	{
		push_4_chunks(stacks, size, stacks->chunk_bot, stacks->chunk_top);
		stacks->chunk_bot += 2;
		stacks->chunk_top -= 2;
		size = size_4_chunks(stacks);
	}
	rotate_pushback(stacks);
	final_rotate(stacks);
	return (1);
}
