/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:10 by abackman          #+#    #+#             */
/*   Updated: 2022/08/01 18:50:18 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_stacks(t_pusha *stacks, int status)
{
	t_stack	*tmp;
	t_stack	*head;

	head = stacks->a_stack->next;
	while (head != stacks->a_stack && head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	if (head != NULL)
		free(head);
	if (stacks->b_stack->next)
		head = stacks->b_stack->next;
	ft_printf("\nFreeing staxx\n");
	while (head != stacks->b_stack && head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	if (head != NULL)
		free(head);
	free(stacks);
	stacks = NULL;
	//system("leaks checker");
	return (return_status(status));
}
