/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:00:18 by abackman          #+#    #+#             */
/*   Updated: 2022/08/03 13:48:25 by abackman         ###   ########.fr       */
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

int	moves_check(t_pusha *stacks)
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
	if (stacks->valid_moves)
		ft_free_arr(stacks->valid_moves, (size_t)11);
	return (check_stacks(stacks));
}

/* int	moves_check(char **valid_moves, t_pusha *stacks)
{
	int		status;
	char	*buf;

	status = 0;
	while (1)
	{
		if (!read(STDIN_FILENO, &buf, 9))
			break ;
		status = valid_move(buf, valid_moves);
		if (status == -1)
		{
			ft_free_arr(valid_moves, (size_t)10);
			return (free_stacks(stacks, -1));
		}
		else
			exec_move(stacks, status);
	}
	return (check_stacks(stacks));	
}
 */
