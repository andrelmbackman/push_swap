/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:10:26 by abackman          #+#    #+#             */
/*   Updated: 2022/06/10 15:19:28 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../../ft_printf/includes/ft_printf.h"

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

typedef struct s_tack;
{
	int	*a_stack;
	int	*b_stack;
	int	min;
	int	max;
	int	elem;
}	t_stack;

#endif
