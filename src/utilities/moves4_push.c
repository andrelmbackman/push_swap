/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:39:28 by abackman          #+#    #+#             */
/*   Updated: 2022/09/21 11:13:36 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Checks in the t_pusha struct whether or not the operation/move (str) should
** be written out to stdout. Also checks if the -v flag was given, and if so
** the stacks in their current state will be written out to stdout.
*/

static int	check_write(t_pusha *stacks, char *str)
{
	if (stacks->print)
		write(STDOUT_FILENO, str, 3);
	if (stacks->v)
		print_stacks(stacks);
	return (1);
}

/*
** Exec_pa takes out a node from the circular double linked list of the b_stack
** and inserts it at the top of the the a_stack.
*/

int	exec_pa(t_pusha *stacks)
{
	t_stack	*tmp;
	int		nullify;

	tmp = stacks->b_stack;
	nullify = 0;
	if (stacks->b_stack == NULL)
		return (0);
	if (stacks->b_stack->next == stacks->b_stack)
		nullify = 1;
	stacks->b_stack = stacks->b_stack->next;
	stacks->b_stack->prev = tmp->prev;
	stacks->b_stack->prev->next = stacks->b_stack;
	if (stacks->a_stack == NULL)
		add_to_empty(stacks->a_stack, tmp);
	else
		add_head(stacks->a_stack, tmp);
	stacks->a_stack = tmp;
	stacks->b_size--;
	stacks->a_size++;
	if (nullify)
		stacks->b_stack = NULL;
	return (check_write(stacks, "pa\n"));
}

/*
** Exec_pb takes out a node from the circular double linked list of the a_stack
** and inserts it at the top of the b_stack
*/

int	exec_pb(t_pusha *stacks)
{
	t_stack	*tmp;
	int		nullify;

	tmp = stacks->a_stack;
	nullify = 0;
	if (stacks->a_stack == NULL)
		return (0);
	if (stacks->a_stack->next == stacks->a_stack)
		nullify = 1;
	stacks->a_stack = stacks->a_stack->next;
	stacks->a_stack->prev = tmp->prev;
	stacks->a_stack->prev->next = stacks->a_stack;
	if (stacks->b_stack == NULL)
		add_to_empty(stacks->b_stack, tmp);
	else
		add_head(stacks->b_stack, tmp);
	stacks->b_stack = tmp;
	stacks->a_size--;
	stacks->b_size++;
	if (nullify)
		stacks->a_stack = NULL;
	return (check_write(stacks, "pb\n"));
}
