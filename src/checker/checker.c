/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 18:26:36 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Iterates through the linked list of saved operations (moves) and executes
** them.
*/

static int	exec_moves(t_pusha *stacks, t_move *head)
{
	t_move	*tmp;

	tmp = head;
	if (head == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		g_pushtable[tmp->index](stacks);
		tmp = tmp->next;
	}
	g_pushtable[tmp->index](stacks);
	if (stacks == NULL || head == NULL)
		return (-1);
	return (1);
}

/*
** Checks whether or not the operations saved are valid ones. Returns 1 if only
** valid moves, -1 if an invalid move and 0 if no moves were found.
*/

static int	valid_move(t_move *head, char **valid)
{
	int		i;
	int		ret;
	t_move	*tmp;

	tmp = head;
	if (head == NULL)
		return (0);
	while (tmp != NULL)
	{
		ret = 0;
		i = 0;
		while (valid[i] != NULL)
		{
			if (!ft_strcmp((const char *)valid[i], (const char *)tmp->str))
			{
				ret = 1;
				tmp->index = i;
			}
			i++;
		}
		if (!ret)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

/*
** Adds a new node at the end of the linked list t_moves and saves the input
** (char *buf) in it.
*/

static int	add_move(t_move **head, char *buf)
{
	t_move	*new;
	t_move	*tmp;

	tmp = NULL;
	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (-1);
	new->next = NULL;
	new->str = ft_strdup((const char *)buf);
	new->index = -1;
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

/*
** Reads from standard input until "end of file" (ctrl + D) and saves all input
** in a linked list. If moves are valid they are executed and then the stacks
** are checked.
*/

static int	moves_check(t_pusha *stacks)
{
	int		status;
	char	*buf;
	t_move	*head;

	status = 0;
	head = NULL;
	buf = NULL;
	while (get_next_line((const int)STDIN_FILENO, &buf))
	{
		if (add_move(&head, buf) < 0)
		{
			ft_strdel(&buf);
			return (free_all(stacks, &head, ERROR));
		}
		else
			ft_strdel(&buf);
	}
	status = valid_move(head, stacks->valid_moves);
	if (status < 0)
		return (free_all(stacks, &head, status));
	else
		exec_moves(stacks, head);
	free_moves(&head);
	ft_free_arr(stacks->valid_moves, (size_t)11);
	return (check_stacks(stacks));
}

int	main(int ac, char **av)
{
	t_pusha		*stacks;
	char		**moves;
	int			ret;

	ret = 0;
	if (ac < 2)
		return (1);
	if (!ft_strcmp((const char *)av[1], (const char *)"-h"))
		return (checker_help());
	stacks = init_stacks();
	if (stacks == NULL)
		return (return_status(ERROR));
	moves = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", (char)32);
	if (moves == NULL)
		return (return_status(ERROR));
	stacks->valid_moves = moves;
	if (check_ints(stacks, ac, av) == -1)
	{
		ft_free_arr(moves, (size_t)11);
		return (-1);
	}
	ret = moves_check(stacks);
	return (ret);
}
