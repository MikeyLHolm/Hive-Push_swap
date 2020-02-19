/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:54:37 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/18 13:26:14 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

// remove
#include <stdio.h>

# define ER_DUP			"Error: Duplicate found!"
# define ER_MALLOC		"Error: Failed Malloc!"
# define ER_NOARG		"Error: No arguments!"
# define ER_NOTINT		"Error: Not an int!"
# define ER_NOVALARG	"Error: No valid arguments!"

/*
**	List inside a stack
*/

typedef	struct			s_lst
{
	int					nb;
	struct s_lst		*next;
	struct s_lst		*previous;
}						t_lst;

/*
**	Struct for a stack.
*/

typedef	struct			s_stack
{
	t_lst				*head;
	// t_lst				*lst;
	int					min;
	int					max;
	int					size;
}						t_stack;

/*
**	General struct for the project.
*/

typedef struct			s_push_swap
{
	t_stack		*stack_aspare;
	t_stack		*stack_bspare;
}						t_push_swap;

void			display_stack(t_lst *lst);
void			exit_error(const char *str);
t_stack			*init_stack(void);
int				main(int ac, char **av);
t_stack			*parse(int ac, char **av);
void			validate(t_lst **lst, int ac, char **av);

/*
**	Operational functions
*/

void			lst_pop_push(t_stack *dst, t_stack *src);		// pa + pb
void			lst_rev_rotate(t_stack *stack);						// rra + rrb
void			lst_rrr(t_stack *stack_a, t_stack *stack_b);	// rrr
void			lst_rotate(t_stack *stack);						// ra + rb
void			lst_rr(t_stack *stack_a, t_stack *stack_b);		// rr
t_stack			*lst_swap(t_stack *stack);						// sa + sb
void			lst_ss(t_stack *stack_a, t_stack *stack_b);		// ss

/*
**	Rest of the list functions.
*/

void			lst_add(t_stack *stack, t_lst *node);
void			lst_free(t_stack *stack);
t_lst			*lst_create_node(int nb);
t_lst			*lst_prepend(t_lst *head, t_lst *node);
t_lst			*lst_pop(t_stack *stack);
void			lst_push(t_stack *stack, t_lst *node);
t_lst			*lst_append(t_lst *head, t_lst *node);
t_lst			*lst_create_append(t_lst *head, int nb);
t_lst			*lst_create_prepend(t_lst *head, int nb);

#endif
