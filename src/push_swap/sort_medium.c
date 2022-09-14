/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:09 by abackman          #+#    #+#             */
/*   Updated: 2022/09/14 18:54:52 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** node_direction looks for 'num' in the stack and returns 1 if it is
** in the first half, -1 if it is in the second half or 0 if it cannot
** be found or if it is at the top of the stack
*/

static int	node_direction(t_stack *a, int size, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	if (tmp == NULL)
		return (0);
	while (tmp->next != a)
	{
		if (tmp->num == num)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (tmp->num != num || i == 0)
		return (0);
	else if (i <= (size / 2))
		return (1);
	else
		return (-1);
}

/*
** pushes back the whole b_stack from the biggest to the smallest number
*/

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

/*
** simple sorting optimized for stack sizes ranging from 6 to 23 numbers.
*/

int	sort_medium(t_pusha *stacks)
{
	int	num;

	num = find_smallest(stacks->a_stack);
	while (stacks->a_size > 3)
	{
		num = find_smallest(stacks->a_stack);
		if (node_direction(stacks->a_stack, stacks->a_size, num) > 0)
		{
			while (stacks->a_stack->num != num)
				exec_ra(stacks);
		}
		else
		{
			while (stacks->a_stack->num != num)
				exec_rra(stacks);
		}
		exec_pb(stacks);
	}
	sort_three(stacks);
	pushback_med(stacks);
	return (0);
}
