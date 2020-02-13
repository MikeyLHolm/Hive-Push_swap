/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:54:37 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/13 15:43:36 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ER_DUP			"Error: Duplicate found!"
# define ER_MALLOC		"Error: Failed Malloc!"
# define ER_NOARG		"Error: No arguments!"
# define ER_NOTINT		"Error: Not an int!"

/*
**	List inside a stack
*/

typedef	struct			s_lst
{
	int					nb;
	struct s_lst		*next;
}						t_lst;

/*
**	Struct for a stack.
*/

typedef	struct			s_stack
{
	int					min;
	int					max;
	int					total;
	t_lst				*lst;
}						t_stack;

/*
**	General struct for the project.
*/

typedef struct			s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}						t_push_swap;

void		display_stack(t_lst *lst);
void		exit_error(const char *str);
int			main(int ac, char **av);
void		validate(t_lst **lst, int ac, char **av);

t_lst		*lst_add(int nb);
t_lst		*lst_prepend(t_lst *head, t_lst *node);
t_lst		*lst_append(t_lst *head, t_lst *node);
t_lst		*lst_add_append(t_lst *head, int nb);
t_lst		*lst_add_prepend(t_lst *head, int nb);

#endif
