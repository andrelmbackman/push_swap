/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:20:05 by abackman          #+#    #+#             */
/*   Updated: 2022/08/29 17:05:14 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* static int	find_smallest(t_stack *b)
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
} */

static int	find_biggest(t_stack *b)
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

int	rotate_pushback(t_pusha *stacks)
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
}

int	rotate_before_push(t_pusha *stacks, int goal, int direction)
{
	//ft_printf("\nrotate_before_push goal: %d, dir: %d\n", goal, direction);
	if (direction > 0)
	{
		while (stacks->a_stack->num != goal)
		{
			/* if (stacks->a_stack->num == find_smallest(stacks->a_stack))
			{
				exec_pb(stacks);
				exec_rr(stacks);
			}
			else */
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
