/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/09/13 13:35:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	exec_moves(t_pusha *stacks, t_move *head)
{
	t_move *tmp;

	tmp = head;
	if (head == NULL)
		return (0);
	//print_stacks(stacks);
	while (tmp->next != NULL)
	{
		g_pushtable[tmp->index](stacks);
		tmp = tmp->next;
	}
	g_pushtable[tmp->index](stacks);
	//print_stacks(stacks);
	if (stacks == NULL || head == NULL)
		return (-1);
	return (1);
}


/* static int	exec_move(t_pusha *stacks, int status)
{
	if (stacks == NULL || status == -1)
		return (-1);
	return (g_pushtable[status](stacks));
} */

static int	valid_move(t_move *head, char **valid)
{
	int		i;
	int		ret;
	t_move	*tmp;

	i = 0;
	ret = 0;
	tmp = head;
	if (head == NULL)
		return (0);
	//ft_printf("\n%s\n", head->str);
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
				//ft_printf("\nvalid_move\n");
			}
			i++;
		}
		if (!ret)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

/* static int	valid_move(char *buf, char **valid)
{
	int	i;

	i = 0;
	while (valid[i] != NULL)
	{
		if (!ft_strcmp((const char *)valid[i], (const char *)buf))
			return (i);
		i++;
	}
	return (-1);
} */

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
		//ft_printf("\nadd_move; new->str: %s\n", new->str);
		return (1);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	//ft_printf("\nadd_move; new->str: %s\n", new->str);
	return (1);
}

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
	//print_stacks(stacks);
	if (status < 0)
		return (free_all(stacks, &head, status));
	else
		exec_moves(stacks, head);
	free_moves(&head);
	ft_free_arr(stacks->valid_moves, (size_t)11);
	return (check_stacks(stacks));
}

/* static int	moves_check(t_pusha *stacks)
{
	int		status;
	char	*buf;
	t_move	*head;

	status = 0;
	head = NULL;
	while (1)
	{
		if (!get_next_line((const int)STDIN_FILENO, &buf))
			break ;
		status = valid_move(buf, stacks->valid_moves);
		ft_strdel(&buf);
		if (status == -1)
		{
			ft_free_arr(stacks->valid_moves, (size_t)11);
			return (free_stacks(stacks, ERROR));
		}
		else
			exec_move(stacks, status);
	}
	ft_strdel(&buf);
	return (check_stacks(stacks));
}
 */

int	main(int ac, char **av)
{
	t_pusha		*stacks;
	char		**moves;
	int			ret;

	ret = 0;
	if (ac < 2)
		return (1);
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
