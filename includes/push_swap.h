/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:54:37 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 13:40:23 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

/*
**	Error management
*/

# define ER_CMD			"Error: Checker command error!"
# define ER_DUP			"Error: Duplicate found!"
# define ER_GNL			"Error: Get Next Line!"
# define ER_MALLOC		"Error: Failed Malloc!"
# define ER_NOARG		"Error: No arguments!"
# define ER_NOTINT		"Error: Not an int!"
# define ER_NOVALARG	"Error: No valid arguments!"

/*
**	Struct for options -h -l -v.
*/

typedef struct		s_options
{
	int				help;
	int				moves;
	int				verbose;
}					t_options;

/*
**	List inside a stack
*/

typedef	struct		s_lst
{
	int				index;
	int				nb;
	struct s_lst	*next;
	struct s_lst	*previous;
}					t_lst;

/*
**	Struct for a stack.
*/

typedef	struct		s_stack
{
	int				min_value;
	int				max_value;
	int				size;
	t_lst			*head;
}					t_stack;

/*
**	General functions.
*/

void				display_stack(t_lst *lst, char c);
int					dist_to_top(t_stack *stack, t_lst *node);
void				exit_error(const char *str);
void				exit_help(void);
long				find_biggest(t_lst *head);
int					find_median(t_stack *stack);
long				find_smallest(t_lst *head);
void				index_stack(t_stack *stack);
t_options			*init_options(void);
t_stack				*init_stack(void);
int					is_rev_sorted(t_lst *stack);
int					is_sorted(t_lst *stack);
t_lst				*look_for_izero(t_stack *stack);
int					main(int ac, char **av);
t_lst				*next_index(t_stack *stack, int index);
t_stack				*parse(int ac, char **av);
void				push_b_until_3(t_stack *stack_a, t_stack *stack_b);
void				sort(t_stack *stack_a, t_stack *stack_b);
void				sort_3(t_stack *stack_a);
void				sort_algo(t_stack *stack_a, t_stack *stack_b);
void				validate(t_lst **lst, int ac, char **av);

/*
**	Operational functions.
*/

void				lst_pop_push(t_stack *dst, t_stack *src, char *str, int pp);
void				lst_rev_rotate(t_stack *stack, char *str, int rrr);
void				lst_rrr(t_stack *stack_a, t_stack *stack_b, int rrr);
void				lst_rotate(t_stack *stack, char *str, int rr);
void				lst_rr(t_stack *stack_a, t_stack *stack_b, int rr);
void				lst_swap(t_stack *stack, char *str, int ss);
void				lst_ss(t_stack *stack_a, t_stack *stack_b, int ss);

/*
**	Rest of the list functions.
*/

void				lst_add(t_stack *stack, t_lst *node);
void				lst_free(t_stack *stack);
t_lst				*lst_create_node(int nb);
t_lst				*lst_pop(t_stack *stack);
void				lst_push(t_stack *stack, t_lst *node);

#endif
