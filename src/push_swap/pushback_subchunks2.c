/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_subchunks2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:09:45 by abackman          #+#    #+#             */
/*   Updated: 2022/09/07 10:33:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_node(t_pusha *stacks, t_stack *lowest)
{
	if (stacks->a_size == 1 && stacks->a_stack->num < lowest->num)
	{
		exec_pa(stacks);
		exec_ra(stacks);
	}
}


int	calculate_moves(t_stack *head, int goal, int size)
{
	int 	ret;
	int		i;
	int		j;
	t_stack	*tmp;

	ret = size;
	i = 0;
	j = 0;
	tmp = head;
	while (i < size)
	{
		if (tmp->num == goal)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i <= (size / 2))
		return (i);
	while (ret-- > i)
		j--;
	return (j);
}

/*
** RETURNS MIN OR MAX, should return number of moves?? save the num?
*/

static int	find_dst(t_pusha *stacks, t_stack *b, int i)
{
	int	min;
	int	max;
	int	x;
	t_stack	*tmp;

	min = stacks->min;
	max = stacks->max;
	x = 0;
	tmp = stacks->a_stack;
	while (++x <= stacks->a_size)
	{
		if (tmp->num > min && tmp->num < b->num)
			min = tmp->num;
		if (tmp->num < max && tmp->num > b->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	if (total_moves(b, min, i, stacks->a_size) < \
	total_moves(b, max, i, stacks->a_size))
		return (min);
	else
		return (max);
}

static int	moves_to_match(t_pusha *stacks, t_stack *b, int i)
{
	int			j;
	t_stack		*tmp;
	int			ret;

	j = 0;
	ret = 2147483647;
	tmp = stacks->a_stack;
	if (stacks->a_stack == NULL || stacks->a_size == 1)
		return (calculate_moves(stacks->b_stack, b->num, stacks->b_size));
	return (find_dst(stacks, b, i));
}

void	one_node(t_pusha *stacks, int min, int max)
{
	t_stack	*tmp;
	t_stack	*lowest;
	int		num;
	int		i;

	tmp = stacks->b_stack;
	lowest = stacks->b_stack;
	i = 0;
	num = 2147483647;
	while (tmp->next != stacks->b_stack)
	{
		if (tmp->num >= min && tmp->num <= max)
		{
			if (ft_abs(moves_to_match(stacks, tmp, i)) < ft_abs(num))
			{
				num = moves_to_match(stacks, tmp, i);
				lowest = tmp;
			}
		}
		i++;
	}
	if (tmp->num >= min && tmp->num <= max && ft_abs(moves_to_match(stacks,\
	tmp, i) < ft_abs(num)))
			lowest = tmp;
	push_node(stacks, lowest);
}
