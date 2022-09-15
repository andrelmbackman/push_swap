/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:33:53 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 18:34:14 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Displays a help message for the checker program.
*/

int	checker_help(void)
{
	ft_printf("usage: ./checker [any amount of unique integers]\n");
	ft_printf("The checker will then wait for instructions, valid ones are: ");
	ft_printf("\nsa sb ss pa pb ra rb rr rra rrb rrr\n");
	ft_printf("After the instructions are given, to flush input: [ctrl] + [D]");
	ft_printf("\nChecker will then display either OK if the instructions\n \
	sorted the stacks, KO if they didn't and error in case of invalid \
	moves.\n");
	return (0);
}

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
