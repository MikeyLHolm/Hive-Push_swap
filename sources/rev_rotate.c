/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:21 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/18 13:27:14 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	rra: reverse rotate a - shift down all elements of stack a by 1.
**		 The last element becomes the first one.
*/

/*
**	rrb: reverse rotate b - shift down all elements of stack b by 1.
**		 The last element becomes the first one.
*/

void		lst_rev_rotate(t_stack *stack)
{
	if (stack && stack->head)
		stack->head = stack->head->previous;
}

/*
**	rrr: rra and rrb at the same time.
*/

void		lst_rrr(t_stack *stack_a, t_stack *stack_b)
{
	lst_rev_rotate(stack_a);
	lst_rev_rotate(stack_b);
}
