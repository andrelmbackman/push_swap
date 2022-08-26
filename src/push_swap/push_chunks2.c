/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:20:05 by abackman          #+#    #+#             */
/*   Updated: 2022/08/26 19:20:51 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rotate_before_push(t_pusha *stacks, int goal, int direction)
{
	ft_printf("\nrotate_before_push goal: %d, dir: %d\n", goal, direction);
	if (direction > 0)
	{
		while (stacks->a_stack->num != goal)
			exec_ra(stacks);
	}
	else
	{
		while (stacks->a_stack->num != goal)
			exec_rra(stacks);
	}
	return (1);
}