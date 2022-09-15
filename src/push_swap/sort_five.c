/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:00:47 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 14:23:37 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Returns 1 if both x and y are matched by either the node a or b respectively.
*/

static int	numbers_match(t_stack *a, t_stack *b, int x, int y)
{
	if ((a->num == x || a->num == y) && (b->num == x || b->num == y))
		return (1);
	return (0);
}

/*
** Finds out if a "double move", which applies to both a_stack and b_stack, is
** beneficial and then executes the move.
*/

static void	find_double_move(t_pusha *stacks)
{
	t_stack	*a;

	a = stacks->a_stack;
	if (stacks->b_stack->num < stacks->b_stack->next->num)
	{
		if (a->prev == a->dst_next || a->next == a->dst_prev)
			exec_ss(stacks);
		else if (a->prev == a->dst_prev && a->num == stacks->max)
			exec_rr(stacks);
		else if (a->prev == a->dst_prev)
			exec_rrr(stacks);
	}
}

/*
** ra_push is called if it requires fewer moves than rra_push to push the
** smallest and 2nd smallest numbers to b_stack.
*/

static int	ra_push(t_pusha *stacks, int min)
{
	while (!sorted(stacks))
	{
		if (stacks->a_size == 3)
			break ;
		if (stacks->a_stack->num == stacks->min || stacks->a_stack->num == min)
			exec_pb(stacks);
		else
			exec_ra(stacks);
	}
	if (sorted(stacks))
		return (1);
	find_double_move(stacks);
	if (stacks->b_stack->num < stacks->b_stack->next->num)
		exec_sb(stacks);
	return (0);
}

/*
** rra_push is called if it requires fewer moves than ra_push to push the
** smallest and 2nd smallest numbers to b_stack.
*/

static int	rra_push(t_pusha *stacks, int min)
{
	while (!sorted(stacks))
	{
		if (stacks->a_size == 3)
			break ;
		if (stacks->a_stack->num == stacks->min || stacks->a_stack->num == min)
			exec_pb(stacks);
		else
			exec_rra(stacks);
	}
	if (sorted(stacks))
		return (1);
	find_double_move(stacks);
	if (stacks->b_stack->num < stacks->b_stack->next->num)
		exec_sb(stacks);
	return (0);
}

/*
** Finds the smallest and 2nd smallest numbers and pushes them to b_stack, then
** calls the algorithm to sort 3 numbers in a_stack before pushing back the
** numbers, which will now sort the full stack.
*/

int	sort_five(t_pusha *stacks)
{
	int		min_save;
	t_stack	*a;

	min_save = stacks->min;
	a = stacks->a_stack;
	while (a->next != stacks->a_stack)
	{
		if (a->num == stacks->min)
			min_save = a->dst_next->num;
		a = a->next;
	}
	if (a->num == stacks->min)
			min_save = a->dst_next->num;
	a = a->next;
	if (numbers_match(a->prev, a->next->next, stacks->min, min_save) \
	|| numbers_match(a->prev, a->prev->prev, stacks->min, min_save))
		rra_push(stacks, min_save);
	else
		ra_push(stacks, min_save);
	stacks->min = min_save;
	sort_three(stacks);
	while (stacks->b_size)
		exec_pa(stacks);
	return (0);
}
