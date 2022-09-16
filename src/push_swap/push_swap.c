/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:56:19 by abackman          #+#    #+#             */
/*   Updated: 2022/09/16 13:15:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Displays a usage message for the push_swap program.
*/

static int	push_swap_help(void)
{
	ft_printf("\n{green}usage: ./push_swap [integers to be sorted]{eoc}\n\n");
	ft_printf("The integers can either be separate arguments or a string.\n");
	ft_printf("push_swap will then check if the arguments are valid.\n");
	ft_printf("If so, instructions (operations) to sort the integers\n");
	ft_printf("will be printed. These are all valid instructions:");
	ft_printf("\n{yellow}sa sb ss pa pb ra rb rr rra rrb rrr{eoc}\n");
	ft_printf("To test it we can pipe the output of\n{purple}push_swap ");
	ft_printf("{eoc}to the input of {cyan}checker{eoc}:{green}\n");
	ft_printf("ARGS=\"4 5 1 2 3\"; ./push_swap $ARGS | ./checker $ARGS{eoc}\n");
	return (0);
}

/*
** Assigns the appropriate number of chunks to divide into (where applicable),
** then calls the appropriate sorting functions for the given stack size.
*/

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

	stacks = NULL;
	if (ac < 2 || !av[1][0])
		return (1);
	if (!ft_strcmp((const char *)av[1], (const char *)"-h"))
		return (push_swap_help());
	stacks = init_stacks();
	if (stacks == NULL)
		return (free_stacks(stacks, ERROR));
	if (check_ints(stacks, ac, av) == -1)
		return (-1);
	sort_stacks(stacks);
	return (free_stacks(stacks, NOMESSAGE));
}
