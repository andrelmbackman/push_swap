/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:10:26 by abackman          #+#    #+#             */
/*   Updated: 2022/09/08 16:43:52 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# define ERROR -1
# define KO 0
# define OK 1
# define NOMESSAGE 10

/* typedef enum e_moves
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
}	t_moves; */

typedef struct s_stack
{
	int				num;
	int				chunk;
	struct s_stack	*dst_next;
	struct s_stack	*dst_prev;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_pusha
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**valid_moves;
	int		min;
	int		max;
	int		a_size;
	int		b_size;
	int		empty;
	int		print;
	int		chunk_no;
	int		chunk_top;
	int		chunk_bot;
}	t_pusha;

/*
** Functions for executing the moves
*/

int	exec_sa(t_pusha *stacks);
int	exec_sb(t_pusha *stacks);
int	exec_ss(t_pusha *stacks);
int	exec_pa(t_pusha *stacks);
int	exec_pb(t_pusha *stacks);
int	exec_ra(t_pusha *stacks);
int	exec_rb(t_pusha *stacks);
int	exec_rr(t_pusha *stacks);
int	exec_rra(t_pusha *stacks);
int	exec_rrb(t_pusha *stacks);
int	exec_rrr(t_pusha *stacks);

typedef int	(*t_pushtable)(t_pusha *stacks);

static const t_pushtable	g_pushtable[12] = {
	exec_sa,
	exec_sb,
	exec_ss,
	exec_pa,
	exec_pb,
	exec_ra,
	exec_rb,
	exec_rr,
	exec_rra,
	exec_rrb,
	exec_rrr,
	NULL
};

/*
** Other functions
*/

int		return_status(int status);
int		check_stacks(t_pusha *stacks);
int		free_stacks(t_pusha *stacks, int status);
int		moves_check(t_pusha *stacks);
int		check_ints(t_pusha *stacks, int ac, char **input);
int		add_stack(t_stack **head, int value);
int		first_stack(t_stack **head, t_stack *new);
int		sort_stacks(t_pusha *stacks);
int		sort_small(t_pusha *stacks);
int		sort_three(t_pusha *stacks);
int		sort_five(t_pusha *stacks);
int		sort_medium(t_pusha *stacks);
int		sorted(t_pusha *stacks);

int		find_quickest(t_stack *b, int *goal);

int		push_chunks(t_pusha *stacks, int count);
//int		rotate_before_push(t_pusha *stacks, int goal, int direction);
int		rotate_pushback(t_pusha *stacks);
void	final_rotate(t_pusha *stacks);
void	print_stacks(t_pusha *stacks);
void	add_head(t_stack *stack, t_stack *new);
void	add_to_empty(t_stack *stack, t_stack *new);
void	get_destined(t_stack *a, int min, int max, int size);
t_pusha	*init_stacks(void);

#endif
