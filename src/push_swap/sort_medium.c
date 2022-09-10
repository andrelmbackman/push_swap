/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:09 by abackman          #+#    #+#             */
/*   Updated: 2022/09/10 16:43:30 by abackman         ###   ########.fr       */
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

static int	node_direction(t_stack *a, int size, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	//ft_printf("\ndirection >> num: %d size; %d\n", num, size);
	if (tmp == NULL)
		return (0);
	while (tmp->next != a)
	{
		if (tmp->num == num)
			break ;
		tmp = tmp->next;
		i++;
	}
	//ft_printf("tmp->num: %d\n", tmp->num);
	if (tmp->num != num || i == 0)
		return (0);
	else if (i < (size / 2))
		return (1);
	else
		return (-1);
}

static void	pushback_med(t_pusha *stacks)
{
	int	num;

	num = stacks->max;
	while (stacks->b_stack != NULL)
	{
		num = find_biggest(stacks->b_stack);
		if (node_direction(stacks->b_stack, stacks->b_size, num) > 1)
		{
			while (stacks->b_stack->num != num)
				exec_rb(stacks);
		}
		else
		{
			while (stacks->b_stack->num != num)
				exec_rrb(stacks);
		}
		exec_pa(stacks);
	}
}

/* static int	three_neighbors(t_stack *a, int size)
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
} */

/* int	rotate_before_push(t_pusha *stacks, int goal, int direction)
{
	//ft_printf("\nrotate_before_push goal: %d, dir: %d\n", goal, direction);
	if (direction > 0)
	{
		while (stacks->a_stack->num != goal)
		{
			//if (stacks->a_stack->num == find_smallest(stacks->a_stack))
			//{
			//	exec_pb(stacks);
			//	exec_rr(stacks);
			//}
			//else
				exec_ra(stacks);
		}
	}
	else
	{
		while (stacks->a_stack->num != goal)
			exec_rra(stacks);
	}
	return (1);
}

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
	if (ret == 0)
		ft_printf("\nno stacks left >> %d %d", chunk1, chunk2);
	return (ret);
}

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
} */

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

int	sort_medium(t_pusha *stacks)
{
	int	num;

	num = find_smallest(stacks->a_stack);
	while (stacks->a_size > 3)
	{
		num = find_smallest(stacks->a_stack);
		//ft_printf("\nsmallest is: %d\n", num);
		if (node_direction(stacks->a_stack, stacks->a_size, num) > 0)
		{
			//ft_printf("\nwill do ra\n");
			while (stacks->a_stack->num != num)
				exec_ra(stacks);
		}
		else
		{
			//ft_printf("\nwill do rra\n");
			while (stacks->a_stack->num != num)
				exec_rra(stacks);
		}
		exec_pb(stacks);
		//print_stacks(stacks);
	}
	sort_three(stacks);
	pushback_med(stacks);
	//print_stacks(stacks);
	//if (!sorted(stacks))
	//	final_rotate(stacks);
	//print_stacks(stacks);
	return (0);
}