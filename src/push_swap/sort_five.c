/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:00:47 by abackman          #+#    #+#             */
/*   Updated: 2022/09/14 18:17:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	numbers_match(t_stack *a, t_stack *b, int x, int y)
{
	if ((a->num == x || a->num == y) && (b->num == x || b->num == y))
		return (1);
	return (0);
}

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

/* static void	find_double_move(t_pusha *stacks)
{
	t_stack	*a;

	a = stacks->a_stack;
	if (stacks->b_stack->num < stacks->b_stack->next->num)
	{
		if (a->num > a->next->num && a->next->num < a->prev->num && \
	a->prev->num < a->num)
			exec_rr(stacks);
		else if (a->num < a->next->num && a->next->num > a->prev->num && \
	a->prev->num < a->num)
			exec_rrr(stacks);
		else if (a->num > a->next->num)
			exec_ss(stacks);
	}
} */

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
	//ft_printf("\nmin_save: %d min: %d\n", min_save, stacks->min);
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
