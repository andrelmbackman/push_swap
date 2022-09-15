/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:10:26 by abackman          #+#    #+#             */
/*   Updated: 2022/09/15 18:28:22 by abackman         ###   ########.fr       */
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

/*
** Struct for saving the numbers in a circular doubly-linked list
*/

typedef struct s_stack
{
	int				num;
	int				chunk;
	struct s_stack	*dst_next;
	struct s_stack	*dst_prev;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
** Main struct that has both stacks and necessary information stored
*/

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
	int		v;
	int		chunk_no;
	int		chunk_top;
	int		chunk_bot;
}	t_pusha;

/*
** Linked list used in checker to store all moves before executing.
*/

typedef struct s_move
{
	char 			*str;
	int				index;
	struct s_move	*next;
}	t_move;

/*
** Functions for executing the moves
*/

int		exec_sa(t_pusha *stacks);
int		exec_sb(t_pusha *stacks);
int		exec_ss(t_pusha *stacks);
int		exec_pa(t_pusha *stacks);
int		exec_pb(t_pusha *stacks);
int		exec_ra(t_pusha *stacks);
int		exec_rb(t_pusha *stacks);
int		exec_rr(t_pusha *stacks);
int		exec_rra(t_pusha *stacks);
int		exec_rrb(t_pusha *stacks);
int		exec_rrr(t_pusha *stacks);


/*
** Function pointer and dispatch table
*/

typedef int					(*t_pushtable)(t_pusha *stacks);

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
** Miscellaneous functions
*/

void	print_stacks(t_pusha *stacks);
void	add_head(t_stack *stack, t_stack *new);
void	add_to_empty(t_stack *stack, t_stack *new);
void	get_destined(t_pusha *stacks, int min, int max, int size);
int		free_moves(t_move **head);
int		free_all(t_pusha *stacks, t_move **head, int message);
int		return_status(int status);
int		check_stacks(t_pusha *stacks);
int		free_stacks(t_pusha *stacks, int status);
int		check_ints(t_pusha *stacks, int ac, char **input);
int		add_stack(t_stack **head, int value);
int		sort_small(t_pusha *stacks);
int		sort_three(t_pusha *stacks);
int		sort_five(t_pusha *stacks);
int		sort_medium(t_pusha *stacks);
int		sorted(t_pusha *stacks);
int		find_smallest(t_stack *b);
int		find_biggest(t_stack *b);
int		find_quickest(t_stack *b, int *goal);
int		sort_big(t_pusha *stacks, int count);
int		rotate_pushback(t_pusha *stacks);
int		checker_help(void);
t_pusha	*init_stacks(void);

#endif
