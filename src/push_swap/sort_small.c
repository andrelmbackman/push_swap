/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:20:29 by abackman          #+#    #+#             */
/*   Updated: 2022/08/04 15:42:40 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sort_three(t_pusha *stacks)
{
	t_stack	*a;

	a = stacks->a_stack;
	if (a->num > a->next->num && a->next->num < a->prev->num && a->prev->num\
	< a->num)
		return (exec_sa(stacks));
}

int	sort_small(t_pusha *stacks)
{
	if (stacks->a_size <= 3)
		return (sort_three(stacks));
	return (0);
}