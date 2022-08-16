/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:20:29 by abackman          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:16 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sort_three(t_pusha *stacks)
{
	t_stack	*a;

	a = stacks->a_stack;
	if (a->num > a->next->num && a->next->num < a->prev->num && a->prev->num\
	> a->num)
		return (exec_sa(stacks));
	else if (a->num > a->next->num && a->next->num < a->prev->num && a->prev->num\
	< a->num)
		return (exec_ra(stacks));
	else if (a->num < a->next->num && a->next->num > a->prev->num && a->prev->num\
	< a->num)
		return (exec_rra(stacks));
	else if (a->num < a->next->num && a->next->num > a->prev->num && a->prev->num\
	> a->num)
	{
		exec_sa(stacks);
		return (exec_ra(stacks));
	}
	else if (a->num > a->next->num && a->next->num > a->prev->num && a->prev->num\
	< a->num)
	{
		exec_sa(stacks);
		return (exec_rra(stacks));
	}
	return (0);
}

static int	sort_two(t_pusha *stacks)
{
	if (stacks->a_stack->num > stacks->a_stack->next->num)
		return (exec_sa(stacks));
	return (0);
}

int	sort_small(t_pusha *stacks)
{
	if (stacks->a_size == 2)
		return (sort_two(stacks));
	if (stacks->a_size <= 3)
		return (sort_three(stacks));
	return (0);
}
