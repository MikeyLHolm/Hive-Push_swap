/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:21 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 09:43:41 by mlindhol         ###   ########.fr       */
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

void		lst_rev_rotate(t_stack *stack, char *str)
{
	if (stack && stack->head)
	{
		stack->head = stack->head->previous;
		ft_printf("%s\n", str);
	}
}

/*
**	rrr: rra and rrb at the same time.
*/

void		lst_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n   ");
	lst_rev_rotate(stack_a, "rra");
	ft_printf("   ");
	lst_rev_rotate(stack_b, "rrb");
}
