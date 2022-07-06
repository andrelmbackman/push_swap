/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:10:26 by abackman          #+#    #+#             */
/*   Updated: 2022/07/06 18:38:55 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# define ERROR -1
# define KO 0
# define OK 1

typedef enum e_moves
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_moves;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pusha
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		min;
	int		max;
	int		a_size;
	int		b_size;
}	t_pusha;

int		return_status(int status);
int		check_stacks(t_pusha *stacks);
int		free_stacks(t_pusha *stacks, int status);
int		check_ints(t_pusha *stacks, int ac, char **input);
t_stack	*add_stack(int value);

#endif
