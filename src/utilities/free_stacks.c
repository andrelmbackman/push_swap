/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:10 by abackman          #+#    #+#             */
/*   Updated: 2022/09/12 14:45:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	print_ab(t_pusha *stacks, t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != stacks->a_stack)
	{
		ft_printf("| %10d\t|", (*a)->num);
		*a = (*a)->next;
	}
	else
		ft_printf("|\t        |");
	if (*b != NULL && (*b)->next != stacks->b_stack)
	{
		ft_printf(" %10d\t|\n", (*b)->num);
		*b = (*b)->next;
	}
	else
		ft_printf("\t        |\n");
	if ((!*a || (*a)->next == stacks->a_stack) && (!*b || \
	(*b)->next == stacks->b_stack))
		return (0);
	return (1);
}

void	print_stacks(t_pusha *stacks)
{
	int		i;
	t_stack	*atmp;
	t_stack	*btmp;

	i = 1;
	atmp = stacks->a_stack;
	btmp = stacks->b_stack;
	ft_printf("\n|\tStack A | Stack B\t|\n+-------------------------------+\n");
	while (i)
		i = print_ab(stacks, &atmp, &btmp);
	if (atmp != NULL)
		ft_printf("| %10d\t|", atmp->num);
	else
		ft_printf("|\t        |");
	if (btmp != NULL)
		ft_printf(" %10d\t|\n", btmp->num);
	else
		ft_printf("\t        |\n");
	ft_printf("+-------------------------------+\n");
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
	//if (!stacks->print)
	//	print_stacks(stacks);
	if (stacks->a_size && stacks->a_stack != NULL)
		del_stack(stacks->a_stack);
	if (stacks->b_size && stacks->b_stack != NULL)
		del_stack(stacks->b_stack);
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
