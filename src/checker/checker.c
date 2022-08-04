/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/08/04 13:37:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	char		**moves;
	int			ret;

	ret = 0;
	if (ac < 2)
		return (1);
	stacks = init_stacks();
	if (stacks == NULL)
		return(return_status(-1));
	moves = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", (char)32);
	if (moves == NULL)
		return(return_status(-1));
	stacks->valid_moves = moves;
	if (check_ints(stacks, ac, av) == -1)
		return (-1);
	ret = moves_check(stacks);
	//ft_free_arr(stacks->valid_moves, (size_t)11);
	return (0);
}
