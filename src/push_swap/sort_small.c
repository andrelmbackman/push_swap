/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:20:29 by abackman          #+#    #+#             */
/*   Updated: 2022/08/17 15:13:45 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sort_two(t_pusha *stacks)
{
	if (stacks->a_stack->num > stacks->a_stack->next->num)
		return (exec_sa(stacks));
	return (0);
}

int	sort_three(t_pusha *stacks)
{
	t_stack	*a;

	a = stacks->a_stack;
	if (a->num > a->next->num && a->next->num < a->prev->num &&\
	 a->prev->num > a->num)
		return (exec_sa(stacks));
	else if (a->num > a->next->num && a->next->num < a->prev->num &&\
	 a->prev->num < a->num)
		return (exec_ra(stacks));
	else if (a->num < a->next->num && a->next->num > a->prev->num &&\
	 a->prev->num < a->num)
		return (exec_rra(stacks));
	else if (a->num < a->next->num && a->next->num > a->prev->num &&\
	 a->prev->num > a->num)
	{
		exec_sa(stacks);
		return (exec_ra(stacks));
	}
	else if (a->num > a->next->num && a->next->num > a->prev->num &&\
	 a->prev->num < a->num)
	{
		exec_sa(stacks);
		return (exec_rra(stacks));
	}
	return (0);
}

static int	sort_four(t_pusha *stacks)
{
	t_stack *a;

	a = stacks->a_stack;
	//ft_printf("\nsort_four\na_stack: %d\nmin: %d\n", a->num, stacks->min);
	if (a->next->num == stacks->min || a->next->next->num == stacks->min)
	{
		while (stacks->a_stack->num != stacks->min)
			exec_ra(stacks);
	}
	else if (a->prev->num == stacks->min)
		exec_rra(stacks);
	if (sorted(stacks))
		return (0);
	exec_pb(stacks);
	sort_three(stacks);
	return (exec_pa(stacks));
}

int	sort_small(t_pusha *stacks)
{
	if (stacks->a_size == 2)
		return (sort_two(stacks));
	else if (stacks->a_size == 3)
		return (sort_three(stacks));
	else if (stacks->a_size == 4)
		return (sort_four(stacks));
	else if (stacks->a_size == 5)
		return (sort_five(stacks));
	return (0);
}
