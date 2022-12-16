/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/09/21 11:12:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Swaps the first two nodes of the a_stack. If called by push_swap and print
** is set to one it will write the command to stdout.
*/

int	exec_sa(t_pusha *stacks)
{
	int	tmp;

	if (stacks->a_size < 2)
		return (0);
	tmp = stacks->a_stack->num;
	stacks->a_stack->num = stacks->a_stack->next->num;
	stacks->a_stack->next->num = tmp;
	tmp = stacks->a_stack->chunk;
	stacks->a_stack->chunk = stacks->a_stack->next->chunk;
	stacks->a_stack->next->chunk = tmp;
	if (stacks->print == 1)
		write(STDOUT_FILENO, "sa\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

/*
** Swaps the first two nodes of the b_stack. If called by push_swap and print
** is set to one it will write the command to stdout.
*/

int	exec_sb(t_pusha *stacks)
{
	int	tmp;

	if (stacks->b_size < 2)
		return (0);
	tmp = stacks->b_stack->num;
	stacks->b_stack->num = stacks->b_stack->next->num;
	stacks->b_stack->next->num = tmp;
	tmp = stacks->b_stack->chunk;
	stacks->b_stack->chunk = stacks->b_stack->next->chunk;
	stacks->b_stack->next->chunk = tmp;
	if (stacks->print == 1)
		write(STDOUT_FILENO, "sb\n", 3);
	if (stacks->v == 1)
		print_stacks(stacks);
	return (1);
}

/*
** Swaps the first two nodes of both a_stack and b_stack.
** If called by push_swap and print is set to one, it is increased so that
** exec_sa and exec_sb do not write out their operations to stdout.
*/

int	exec_ss(t_pusha *stacks)
{
	if (stacks->print)
		stacks->print = 2;
	if (stacks->v)
		stacks->v = 2;
	exec_sa(stacks);
	exec_sb(stacks);
	if (stacks->print == 2)
	{
		write(STDOUT_FILENO, "ss\n", 3);
		stacks->print = 1;
	}
	if (stacks->v == 2)
	{
		print_stacks(stacks);
		stacks->v = 1;
	}
	return (1);
}
