/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/07/06 18:39:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	return_status(int status)
{
	if (status < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	else if (status > 0)
	{
		ft_putstr_fd("OK\n", STDOUT_FILENO);
		return (1);
	}
	else
	{
		ft_putstr_fd("KO\n", STDERR_FILENO);
		return (0);
	}
}

/* static int	check_moves(const char **valid_moves, t_pusha *stacks)
{
	char	buf[100];
	int		status;

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
			execute_move(stacks, status);
	}
	return (check_stacks(stacks));
} */

int	main(int ac, char **av)
{
	t_pusha		*stacks;
	char		**valid_moves;

	if (ac < 2)
		return (1);
	stacks = (t_pusha *)malloc(sizeof(t_pusha));
	if (!stacks)
		return(return_status(-1));
	valid_moves = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", (char)32);
	if (valid_moves == NULL)
		return(return_status(-1));
	if (check_ints(stacks, ac, av) == -1)
		return (return_status(-1));
	//return (check_moves(valid_moves, stacks));
	return (check_stacks(stacks));
}
