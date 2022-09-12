/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/09/12 15:36:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	exec_move(t_pusha *stacks, int status)
{
	if (stacks == NULL || status == -1)
		return (-1);
	return (g_pushtable[status](stacks));
}

static int	valid_move(char *buf, char **valid)
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
}

static int	moves_check(t_pusha *stacks)
{
	int		status;
	char	*buf;

	status = 0;
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
		return (return_status(-1));
	moves = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", (char)32);
	if (moves == NULL)
		return (return_status(-1));
	stacks->valid_moves = moves;
	if (check_ints(stacks, ac, av) == -1)
	{
		ft_free_arr(moves, (size_t)11);
		return (-1);
	}
	ret = moves_check(stacks);
	ft_free_arr(stacks->valid_moves, (size_t)11);
	return (ret);
}
