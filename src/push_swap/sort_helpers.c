/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:20:05 by abackman          #+#    #+#             */
/*   Updated: 2022/10/11 17:57:05 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Iterates through the stack and returns the biggest integer found.
*/

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
	return (max);
}

/*
** Iterates through the stack and returns the smallest integer found.
*/

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
	return (min);
}

/*
** Helper function for find_quickest. Returns 1 if the rotating direction
** should be RA/RB and -1 if it should be RRA/RRB.
*/

static int	find_quickest_return(int front, int back, int *goal)
{
	if (front == *goal && back != *goal)
		return (1);
	else
		return (-1);
}

/*
** Finds the smallest and biggest number in the stack, decides which one of them
** requires fewer moves to rotate to the top and assigns that number to *goal.
** Returns either 1 or -1 depending on the direction of the rotation.
*/

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
	return (find_quickest_return(front->num, back->num, goal));
}

/*
** Pushes back all of b_stack to a_stack. Rotates either the smallest or largest
** number to the top of b_stack (whichever is quicker), pushes it to a_stack and
** if it was the smallest one it is rotated to the bottom of a_stack.
*/

/* int	rotate_pushback(t_pusha *stacks)
{
	int		goal;
	int		dir;

	goal = 0;
	while (stacks->b_stack != NULL)
	{
		dir = find_quickest(stacks->b_stack, &goal);
		while (stacks->b_stack->num != goal && dir < 0)
			exec_rrb(stacks);
		while (stacks->b_stack->num != goal && dir > 0)
			exec_rb(stacks);
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
	return (1);
} */

static int	find_fastest(t_pusha *stacks, t_stack *dst, int *goal)
{
	int		i;
	t_stack	*tmp;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	tmp = stacks->b_stack;
	a = dst->dst_prev;
	b = dst->prev->dst_next;
	if (tmp == a || tmp == b)
		return (0);
	while (tmp->next != stacks->b_stack)
	{
		if (tmp == a || tmp == b)
			break ;
		tmp = tmp->next;
		i++;
	}
	*goal = tmp->num;
	if (i < (stacks->b_size / 2))
		return (1);
	else
		return (-1);
}

/*
** BOTH THESE FUNCTIONS ARE TEMPORARY AND FAULTY, FIX
*/

int	rotate_pushback(t_pusha *stacks)
{
	t_stack	*tmp;
	int		dir;
	int		goal;

	exec_pa(stacks);
	tmp = stacks->a_stack;
	while (stacks->b_stack != NULL)
	{
		dir = find_fastest(stacks, tmp, &goal);
		while (stacks->b_stack->num != goal && dir < 0)
			exec_rrb(stacks);
		while (stacks->b_stack->num != goal && dir > 0)
			exec_rb(stacks);
		exec_pa(stacks);
		tmp = stacks->a_stack;
		if (stacks->b_stack == NULL)
			break ;
		if (stacks->a_stack->next != stacks->a_stack->dst_next)
		{
			if (find_fastest(stacks, tmp, &goal))
				exec_rr(stacks);
			else
				exec_ra(stacks);
		}
		tmp = stacks->a_stack;
	}
	//print_stacks(stacks);
	return (1);
}