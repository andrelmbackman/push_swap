/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:42:46 by abackman          #+#    #+#             */
/*   Updated: 2022/08/18 18:28:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* static int	check_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if ((a->num > a->next->num) && (b->num < b->next->num) && (a->next->num \
	> b->next->num))
		return (1);
	return (0);
}

static int	check_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (a->num > a->prev->num)
	{
		if (b->num > b->prev->num || b->prev->num < b->prev->prev->num)
			return (1);
	}
	return (0);
} */

static int	check_rr(t_stack *a, t_stack *b, int pivot)
{
	if (a == 0 || b == 0)
		return (0);
	if (a->num > pivot)
	{
		if (b->num < b->prev->num || b->num < b->next->num)
			return (1);
	}
	return (0);
}

int	quicksort(t_pusha *stacks)
{
	int		pivot;
	t_stack	*tmp;

	pivot = 0;
	tmp = stacks->a_stack->prev;
	while (!sorted(stacks))
	{
		tmp = stacks->a_stack->prev;
		pivot = tmp->num;
		while(stacks->a_stack != tmp)
		{
			if (check_rr(stacks->a_stack, stacks->b_stack, pivot))
				exec_rr(stacks);
			else if (stacks->a_stack->num > pivot)
				exec_pb(stacks);
			else
				exec_ra(stacks);
			//ft_printf("\n\npivot: %d a->num: %d tmp->num: %d\n\n", pivot, stacks->a_stack->num, tmp->num);
		}
		//ft_printf("\nDO YOU EVEN BREAK?\nnum: %d, pivot: %d\n", stacks->a_stack->num, pivot);
		/* if (check_rrr(stacks->a_stack, stacks->b_stack))
			exec_rrr(stacks);
		else if (check_ss(stacks->a_stack, stacks->b_stack))
			exec_ss(stacks); */
		while (stacks->b_stack)
			exec_pa(stacks);
	}
	return (1);
}