/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:56:19 by abackman          #+#    #+#             */
/*   Updated: 2022/08/23 18:57:34 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(t_pusha *stacks)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stacks->a_stack;
	tmp = head;
	//ft_printf("\nAre they sorted?\n");
	if (stacks->b_size != 0 || stacks->b_stack != NULL)
		return (0);
	while (tmp->next != head && stacks->a_size > 1)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	 if (tmp->num < tmp->next->num)
		return (0);
	//ft_printf("\nThey are sorted\n");
	return (1);
}

int	sort_stacks(t_pusha *stacks)
{
	if (stacks->a_size <= 1 || stacks->a_stack == NULL)
		return (-1);
	stacks->print = 1;
	if (sorted(stacks))
		return (1);
	else if (stacks->a_size <= 5)
		return (sort_small(stacks));
	else
		return(alphasort(stacks));
	return (0);
}

int	main(int ac, char **av)
{
	t_pusha	*stacks;

	if (ac < 2 || !av[1][0])
		return (1);
	stacks = init_stacks();
	if (stacks == NULL)
		return (free_stacks(stacks, ERROR));
	if (check_ints(stacks, ac, av) == -1)
		return (-1);
	sort_stacks(stacks);
	return (free_stacks(stacks, NOMESSAGE));
}
