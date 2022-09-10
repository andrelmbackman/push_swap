/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:20:05 by abackman          #+#    #+#             */
/*   Updated: 2022/09/09 14:37:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_biggest(t_stack *b)
{
	t_stack	*tmp;
	int		max;

	max = -2147483648;
	tmp = b;
	while (tmp->next != b)
	{
		if (tmp->num >= max)
			max = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num >= max)
			max = tmp->num;
	//ft_printf("\nmax: %d\n", max);
	return (max);
}

int	find_smallest(t_stack *b)
{
	t_stack	*tmp;
	int		min;

	min = 2147483647;
	tmp = b;
	while (tmp->next != b)
	{
		if (tmp->num <= min)
			min = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num <= min)
			min = tmp->num;
	//ft_printf("\nmax: %d\n", max);
	return (min);
}

static int	find_quickest_return(int front, int back, int *goal)
{
	//ft_printf("\ngoing mad. front: %d back: %d goal :%d\n", front, back, *goal);
	if (front == *goal && back != *goal)
		return (1);
	else
		return (-1);
}

int	find_quickest(t_stack *b, int *goal)
{
	t_stack	*front;
	t_stack	*back;
	int		min;
	int		max;

	front = b;
	back = b;
	min = find_smallest(b);
	max = find_biggest(b);
	while (front->next != back && back->prev != front)
	{
		if (front->num == min || front->num == max || back->num == min || \
		back->num == max)
			break ;
		front = front->next;
		back = back->prev;
		if (front == back)
			break ;
	}
	if (back->num == max || front->num == max)
		*goal = max;
	else
		*goal = min;
	//ft_printf("\nfind_quickest max: %d, min: %d goal: %d\nfront: %d back: %d\n", max, min, *goal, front->num, back->num);
	return (find_quickest_return(front->num, back->num, goal));
}


int	rotate_pushback(t_pusha *stacks)
{
	int		goal;
	t_stack	*tmp;

	goal = 0;
	while (stacks->b_stack != NULL)
	{
		tmp = stacks->b_stack;
		if (find_quickest(stacks->b_stack, &goal) < 0)
		{
			//ft_printf("\ngoal: %d\n", goal);
			while (stacks->b_stack->num != goal)
				exec_rrb(stacks);
		}
		else
		{
			while (stacks->b_stack->num != goal)
				exec_rb(stacks);
		}
		exec_pa(stacks);
		if (stacks->b_stack == NULL)
			break ;
		if (goal < find_smallest(stacks->b_stack))
		{
			if (find_quickest(stacks->b_stack, &goal) > 0)
				exec_rr(stacks);
			else
				exec_ra(stacks);
		}
	}
	//print_stacks(stacks);
	return (1);
}

/* int	rotate_pushback(t_pusha *stacks)
{
	t_stack	*tmp;
	int		i;
	int		max;

	while (stacks->b_stack != NULL && stacks->b_size)
	{
		tmp = stacks->b_stack;
		i = 0;
		max = find_biggest(stacks->b_stack);
		while (tmp->num != max)
		{
			i++;
			tmp = tmp->next;
		}
		//ft_printf("\ntmp->num: %d\n", tmp->num);
		if (i > (stacks->b_size / 2))
		{
			while (stacks->b_stack->num != max)
				exec_rrb(stacks);
		}
		else
		{
			while (stacks->b_stack->num != max)
				exec_rb(stacks);
		}
		exec_pa(stacks);
	}
	return (1);
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
} */
