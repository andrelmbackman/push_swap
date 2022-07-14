/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/07/14 15:16:26 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_sa(t_pusha *stacks)
{
	return (1);
}

int	exec_sb(t_pusha *stacks)
{
	return (1);
}

int	exec_ss(t_pusha *stacks)
{
	if (!exec_sa(stacks))
		return (0);
	if (!exec_sb(stacks))
		return (0);
	return (1);
}

int	exec_pa(t_pusha *stacks)
{
	return (1);
}

int	exec_pb(t_pusha *stacks)
{
	return (1);
}