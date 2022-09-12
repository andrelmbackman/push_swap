/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:09 by abackman          #+#    #+#             */
/*   Updated: 2022/09/12 15:12:40 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	node_direction(t_stack *a, int size, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	//ft_printf("\ndirection >> num: %d size; %d\n", num, size);
	if (tmp == NULL)
		return (0);
	while (tmp->next != a)
	{
		if (tmp->num == num)
			break ;
		tmp = tmp->next;
		i++;
	}
	//ft_printf("tmp->num: %d\n", tmp->num);
	if (tmp->num != num || i == 0)
		return (0);
	else if (i < (size / 2))
		return (1);
	else
		return (-1);
}

static void	pushback_med(t_pusha *stacks)
{
	int	num;

	num = stacks->max;
	while (stacks->b_stack != NULL)
	{
		num = find_biggest(stacks->b_stack);
		if (node_direction(stacks->b_stack, stacks->b_size, num) > 1)
		{
			while (stacks->b_stack->num != num)
				exec_rb(stacks);
		}
		else
		{
			while (stacks->b_stack->num != num)
				exec_rrb(stacks);
		}
		exec_pa(stacks);
	}
}

int	sort_medium(t_pusha *stacks)
{
	int	num;

	num = find_smallest(stacks->a_stack);
	while (stacks->a_size > 3)
	{
		num = find_smallest(stacks->a_stack);
		//ft_printf("\nsmallest is: %d\n", num);
		if (node_direction(stacks->a_stack, stacks->a_size, num) > 0)
		{
			//ft_printf("\nwill do ra\n");
			while (stacks->a_stack->num != num)
				exec_ra(stacks);
		}
		else
		{
			//ft_printf("\nwill do rra\n");
			while (stacks->a_stack->num != num)
				exec_rra(stacks);
		}
		exec_pb(stacks);
		//print_stacks(stacks);
	}
	sort_three(stacks);
	pushback_med(stacks);
	//print_stacks(stacks);
	//if (!sorted(stacks))
	//	final_rotate(stacks);
	//print_stacks(stacks);
	return (0);
}