/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/06/30 12:38:16 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	return_status(int status)
{
	if (status < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	else if (status > 0)
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		return (1);
	}
	else
	{
		ft_putstr_fd("OK\n", STDERR_FILENO);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_pusha	*stacks;
	char	**moves;

	if (ac < 2)
		return (1);
	stacks = (t_pusha *)malloc(sizeof(t_pusha));
	if (!stacks)
		return(return_status(-1));
	moves = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", (char)32);
	if (moves == NULL)
		return(return_status(-1));
	if (!check_input(&stacks, ac, av))
		return (return_status(-1));
	
}
