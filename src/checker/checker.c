/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/08/11 13:43:22 by abackman         ###   ########.fr       */
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
/* static char	**get_moves(void)
{
	char	ret[12];

	//ret = (char **)malloc(12 * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup("sa");
	ret[1] = ft_strdup("sb");
	ret[2] = ft_strdup("ss");
	ret[3] = ft_strdup("pa");
	ret[4] = ft_strdup("pb");
	ret[5] = ft_strdup("ra");
	ret[6] = ft_strdup("rb");
	ret[7] = ft_strdup("rr");
	ret[8] = ft_strdup("rra");
	ret[9] = ft_strdup("rrb");
	ret[10] = ft_strdup("rrr");
	ret[0] = "sa";
	ret[1] = "sb";
	ret[2] = "ss";
	ret[3] = "pa";
	ret[4] = "pb";
	ret[5] = "ra";
	ret[6] = "rb";
	ret[7] = "rr";
	ret[8] = "rra";
	ret[9] = "rrb";
	ret[10] = "rrr";
	ret[11] = NULL;
	return (ret);
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
	//moves = get_moves();
	if (moves == NULL)
		return(return_status(-1));
	stacks->valid_moves = moves;
	if (check_ints(stacks, ac, av) == -1)
	{
		//ft_free_arr(moves, (size_t)11);
		return (-1);
	}
	ret = moves_check(stacks);
	//ft_free_arr(stacks->valid_moves, (size_t)11);
	return (ret);
}
