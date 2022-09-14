/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:56:19 by abackman          #+#    #+#             */
/*   Updated: 2022/09/14 18:49:07 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sort_stacks(t_pusha *stacks)
{
	if (stacks->a_size <= 1 || stacks->a_stack == NULL)
		return (-1);
	stacks->print = 1;
	if (stacks->a_size > 299)
		stacks->chunk_no = 32;
	else if (stacks->a_size > 149)
		stacks->chunk_no = 24;
	stacks->chunk_top = (stacks->chunk_no / 2) + 2;
	stacks->chunk_bot = (stacks->chunk_no / 2) - 1;
	get_destined(stacks, stacks->min, stacks->max, stacks->a_size);
	if (sorted(stacks))
		return (1);
	else if (stacks->a_size <= 5)
		return (sort_small(stacks));
	else if (stacks->a_size < 24)
		return (sort_medium(stacks));
	else
		return (sort_big(stacks, stacks->chunk_no));
}

int	main(int ac, char **av)
{
	t_pusha	*stacks;

	if (ac < 2 || !av[1][0])
		return (1);
	stacks = init_stacks();
	if (stacks == NULL)
		return (free_stacks(stacks, ERROR));
	if (check_ints(stacks, ac, av) == -1)
		return (-1);
	sort_stacks(stacks);
	return (free_stacks(stacks, NOMESSAGE));
}
