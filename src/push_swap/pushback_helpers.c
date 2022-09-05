/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:03:47 by abackman          #+#    #+#             */
/*   Updated: 2022/09/05 18:22:47 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	int_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	total_moves(t_stack *head, int n, int i, int size)
{
	t_stack	*tmp;
	int		j;
	int		ret;

	tmp = head;
	j = -1;
	ret = 0;
	while (++j <= size)
	{
		if (tmp->num == n)
			break ;
		tmp = tmp->next;
	}
	ret = i - calculate_moves(head, n, size);
	return (int_abs(ret));
}
