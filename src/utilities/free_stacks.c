/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:10 by abackman          #+#    #+#             */
/*   Updated: 2022/08/16 18:25:54 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
static void	print_stacks(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	tmp = stacks->a_stack;
	head = stacks->a_stack;
	while (tmp->next != head)
	{
		ft_printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	ft_printf("%d ", tmp->num);
}

int	return_status(int status)
{
	if (status < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	else if (status > 0)
	{
		ft_putstr_fd("OK\n", STDOUT_FILENO);
		return (1);
	}
	else
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		return (0);
	}
}

static int	del_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*next;
	t_stack	*head;

	if (stack == NULL)
		return (0);
	tmp = stack;
	head = stack;
	while (tmp->next != head)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

int	free_stacks(t_pusha *stacks, int status)
{
	if (!stacks->print)
		print_stacks(stacks);
	if (stacks->a_size && stacks->a_stack != NULL)
		del_stack(stacks->a_stack);
	if (stacks->b_size && stacks->b_stack != NULL)
		del_stack(stacks->b_stack);
	//ft_printf("\nFreeing staxx\n");
	if (stacks)
	{
		free(stacks);
		stacks = NULL;
	}
	if (status >= -1 && status <= 1)
		return (return_status(status));
	else
		return (0);
}
