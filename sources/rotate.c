/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:31 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/29 12:57:56 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	ra:	rotate a/b - shift up all elements of stack a by 1.
**		The first element becomes the last one.
*/

void		lst_rotate(t_stack *stack, char *str, int rr)
{
	if (stack && stack->head)
	{
		stack->head = stack->head->next;
		if (rr == 0)
			ft_putendl(str);
	}
}

/*
**	rr:	ra and rb at the same time.
*/

void		lst_rr(t_stack *stack_a, t_stack *stack_b, int rr)
{
	lst_rotate(stack_a, "ra", 1);
	lst_rotate(stack_b, "rb", 1);
	if (rr == 0)
		ft_putendl("rr");
}
