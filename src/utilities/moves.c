/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:43:00 by abackman          #+#    #+#             */
/*   Updated: 2022/06/13 16:35:27 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
t_stack	*free_stack(t_stack *stack)
{
	free(stack->a_stack);
	free(stack->b_stack);
	free(stack);
	return (NULL);
}

static int	validate_input(t_stack **stack, char *input)
{
	int			i;
	long long	tmp;

	i = 0;
	while (input[i])
	{
		tmp = ft_atoi()
	}
}

t_stack	*check_input(int ac, char **input)
{
	int		ret;
	int		count;
	t_stack	*stack;

	ret = 0;
	count = 2;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	while (count <= ac)
	{
		ret = validate_input(&stack, input[count - 1]);
		if (!ret)
			break ;
		count++;
	}
	return (stack);
}