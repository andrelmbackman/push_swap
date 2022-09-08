/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:09 by abackman          #+#    #+#             */
/*   Updated: 2022/09/08 20:28:40 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
static int	three_neighbors(t_stack *a, int size)
{
	int	ret;

	ret = 0;
	if (size != 3)
		return (0);
	if (a->next == a->dst_next || a->next == a->dst_prev)
		ret++;
	if (a->prev == a->dst_next || a->next == a->dst_prev)
		ret++;
	if (ret == 2)
		return (1);
	else
		return (0);
}

static void	pb_minmax(t_pusha *stacks)
{
	int	goal;
	int	dir;

	goal = 0;
	dir = 0;
	dir = find_quickest(stacks->a_stack, &goal);
	//ft_printf("\ndir: %d goal: %d\n", dir, goal);
	//return ;
	if (dir > 0)
	{
		//ft_printf("SHOULD NOT F");
		if (stacks->b_stack != NULL)
		{
			if (stacks->b_stack->next->num != stacks->b_stack->dst_prev->num)
				exec_rr(stacks);
		}
		while (stacks->a_stack->num != goal)
			exec_ra(stacks);
	}
	else
	{
		while (stacks->a_stack->num != goal)
		{
			//ft_printf("HELLO");
			exec_rra(stacks);
		}
	}
	exec_pb(stacks);
}

int	sort_medium(t_pusha *stacks)
{
	int	goal;

	goal = 2147483647;
	while (stacks->a_stack != NULL)
	{
		pb_minmax(stacks);
		//ft_printf("\nafter pb_minmax\n astack: %p asize: %d", stacks->a_stack, stacks->a_size);
		if (three_neighbors(stacks->a_stack, stacks->a_size))
		{
			//ft_printf("\nthere are three neighbors\n");
			sort_three(stacks);
			break ;
		}
		//ft_printf("\npassing the statement?\n%p %p\n", stacks->b_stack->next, stacks->b_stack->dst_prev);
		if (stacks->b_stack->next->num != stacks->b_stack->dst_prev->num && \
		stacks->b_size > 1)
		{
			if (find_quickest(stacks->a_stack, &goal) > 0)
				exec_rr(stacks);
			else
				exec_rb(stacks);
		}
	}
	rotate_pushback(stacks);
	final_rotate(stacks);
	return (1);
}