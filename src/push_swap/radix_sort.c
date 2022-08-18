/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:11:27 by abackman          #+#    #+#             */
/*   Updated: 2022/08/17 18:14:01 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** First sort % 10, then ((% 100) - % 10)
*/

/* static int	radix_cmp(int value, int digit)
{
	int	tmp;
	int	count;
	int	mod;

	tmp = 0;
	count = 1;
	mod = 10;
	while (count <= digit)
	{
		if (count == 1)
			tmp = value % mod;
		else
			tmp = (value % mod) - (value % (mod / 10));
		count++;
		mod *= 10;
	}
	if (tmp)
	{
		while (tmp % 10 == 0)
			tmp /= 10;
	}
	return (tmp);
} */

static int	get_length(int max)
{
	int		len;

	len = 0;
	while (max >> len != 0)
		len++;
	return (len);
}
/*
** Check mod 10, 9 and so on of every size
*/

int	radix_sort(t_pusha *stacks)
{
	int		len;
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	len = get_length(stacks->max);
	//ft_printf("\nlen: %d\nmax: %d\n", len, stacks->max);
	tmp = stacks->a_stack;
	i = 0;
	j = 1;
	size = stacks->a_size;
	while (i <= len)
	{
		if (sorted(stacks))
			return (1);
		j = 0;
		while (j < size)
		{
			tmp = stacks->a_stack;
			if (((tmp->num >> i) & 1) == 1)
			{
				if (stacks->b_stack && (stacks->b_stack->num < \
				stacks->b_stack->next->num && stacks->b_stack->num > stacks->b_stack->prev->num))
					exec_rr(stacks);
				else
					exec_ra(stacks);
			}
			else
				exec_pb(stacks);
			j++;
		}
		while (stacks->b_stack)
			exec_pa(stacks);
		i++;
	}
	if (sorted(stacks))
		return (1);
	else
		return (-1);
}

/*
** digit-wise comparison
*/
/* static int	ft_pow(int num, int pow)
{
	int	i;
	int	ret;

	i = 0;
	ret = num;
	while (++i < pow)
		ret *= ret;
	return (ret);
} */

/* int	radix_sort(t_pusha *stacks)
{
	int		len;
	int		i;
	int		j;
	int		size;
	int		count;
	t_stack	*tmp;

	len = ft_longlen((long)stacks->max);
	//ft_printf("\nlen: %d\nmax: %d\n", len, stacks->max);
	tmp = stacks->a_stack;
	i = 1;
	j = 1;
	count = 1;
	size = stacks->a_size;
	while (i <= len)
	{
		if (sorted(stacks))
			return (1);
		count = 0;
		while (count < 10)
		{
			j = 0;
			while (j < size)
			{
				tmp = stacks->a_stack;
				if (radix_cmp(tmp->num, i) == count)
					exec_pb(stacks);
				else
					exec_ra(stacks);
				j++;
			}
			count++;
		}
		while (stacks->b_stack)
			exec_pa(stacks);
		i++;
	}
	ft_printf("\nare we out?\n");
	if (sorted(stacks))
		return (1);
	else
		return (-1);
} */