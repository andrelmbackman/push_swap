/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:07:57 by abackman          #+#    #+#             */
/*   Updated: 2022/06/10 15:39:34 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	return_status(char *str, int status)
{
	if (status < 0)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		return (-1);
	}
	else if (status > 0)
	{
		ft_putstr_fd("KO", STDOUT_FILENO);
		return (1);
	}
	else
	{
		ft_putstr_fd("OK", STDERR_FILENO);
		return (0);
	}
}

static char	**init_moves(void)
{
	char	**str;

	str = (char **)malloc(12 * sizeof(char *));
	if (!str)
		return (NULL);
	str[0] = ft_strdup("sa");
	str[1] = ft_strdup("sb");
	str[2] = ft_strdup("ss");
	str[3] = ft_strdup("pa");
	str[4] = ft_strdup("pb");
	str[5] = ft_strdup("ra");
	str[6] = ft_strdup("rb");
	str[7] = ft_strdup("rr");
	str[8] = ft_strdup("rra");
	str[9] = ft_strdup("rrb");
	str[10] = ft_strdup("rrr");
	str[11] = NULL;
	return (str);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	**moves;
	
	if (ac < 2)
		return (1);
	moves = init_moves();
}