/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphasort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:11:27 by abackman          #+#    #+#             */
/*   Updated: 2022/08/26 19:14:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	alphasort(t_pusha *stacks)
{
	t_stack	*tmp;
	t_stack	*head;

	get_destined(stacks->a_stack, stacks->min, stacks->max);
	tmp = stacks->a_stack;
	head = tmp;
	/* while (tmp->next != head)
	{
		ft_printf("\nnum: %d, next: %d, prev: %d\n", tmp->num, tmp->dst_next->num, tmp->dst_prev->num);
		tmp = tmp->next;
	}
	ft_printf("\nnum: %d, next: %d, prev: %d\n", tmp->num, tmp->dst_next->num, tmp->dst_prev->num);
 */	return (0);
}
