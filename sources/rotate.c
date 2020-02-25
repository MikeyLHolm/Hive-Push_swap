/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:31 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 09:44:27 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	ra:	rotate a - shift up all elements of stack a by 1.
**		The first element becomes the last one.
*/

void		lst_rotate(t_stack *stack, char *str)
{
	if (stack && stack->head)
	{
		stack->head = stack->head->next;
		ft_printf("%s\n", str);
	}
}

/*
**	rb:	rotate b - shift up all elements of stack b by 1.
**		The first element becomes the last one.
*/

/*
**	rr:	ra and rb at the same time.
*/

void		lst_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n   ");
	lst_rotate(stack_a, "ra");
	ft_printf("   ");
	lst_rotate(stack_b, "rb");
}
