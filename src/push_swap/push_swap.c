/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:56:19 by abackman          #+#    #+#             */
/*   Updated: 2022/09/13 10:36:27 by abackman         ###   ########.fr       */
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
		return(sort_big(stacks, stacks->chunk_no));
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
	//print_stacks(stacks);
	sort_stacks(stacks);
	return (free_stacks(stacks, NOMESSAGE));
}

/* #include <fcntl.h>

int	main(void)
{
	t_pusha	*stacks;
	char	*buf;
	char	*buf1[2];
	int 	fp = open("7_permutations.txt", O_RDONLY);

	if (fp < 0)
		return (-1);
	buf1[0] = NULL;
	while (get_next_line(fp, &buf))
	{
		stacks = init_stacks();
		//ft_printf("\n%s\n", buf);
		if (stacks == NULL)
			return (free_stacks(stacks, ERROR));
		buf1[1] = buf;
		if (check_ints(stacks, 2, buf1) == -1)
			return (-1);
		stacks->chunk_no = 6;
		get_destined(stacks, stacks->min, stacks->max, stacks->a_size);
		buf = strjoin_pro("./checker ", buf, 2);
		system((const char *)buf);
		sort_stacks(stacks);
		free_stacks(stacks, NOMESSAGE);
		ft_strdel(&buf);
	}
	return (0);
} */