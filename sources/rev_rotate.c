/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:21 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/29 12:55:41 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	rra: reverse rotate a/b - shift down all elements of stack a by 1.
**		 The last element becomes the first one.
*/

void		lst_rev_rotate(t_stack *stack, char *str, int rrr)
{
	if (stack && stack->head)
	{
		stack->head = stack->head->previous;
		if (rrr == 0)
			ft_putendl(str);
	}
}

/*
**	rrr: rra and rrb at the same time.
*/

void		lst_rrr(t_stack *stack_a, t_stack *stack_b, int rrr)
{
	lst_rev_rotate(stack_a, "rra", 1);
	lst_rev_rotate(stack_b, "rrb", 1);
	if (rrr == 0)
		ft_putendl("rrr");
}
