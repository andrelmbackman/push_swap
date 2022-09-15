/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:33:53 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 13:51:44 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Frees the whole linked list t_move.
*/

int	free_moves(t_move **head)
{
	t_move	*new;
	t_move	*next;

	if (head == NULL)
		return (0);
	new = *head;
	while (new)
	{
		next = new->next;
		ft_strdel(&new->str);
		free(new);
		new = NULL;
		new = next;
	}
	return (1);
}

/*
** Frees the linked list t_move, the array char **valid_moves and main struct.
*/

int	free_all(t_pusha *stacks, t_move **head, int message)
{
	free_moves(head);
	ft_free_arr(stacks->valid_moves, (size_t)11);
	return (free_stacks(stacks, message));
}
