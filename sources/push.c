/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 08:36:56 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	pa:	push a - take the first element at the top of b and
**		put it at the top of a. Do nothing if b is empty.
**	ie. make b-head >> a-head and del b-head.
*/

void			lst_pop_push(t_stack *dst, t_stack *src, char *str, int pp)
{
	lst_push(dst, lst_pop(src));
	if (pp == 0)
		ft_putendl(str);
}

/*
**	push b until a has 3 elements left. Protecting smallest and largest.
**	Push in two parts. First indexes that are smaller than stack->size / 2 and
**	after that rest until stack has just 3 numbers left.
*/

void			push_b_until_3(t_stack *stack_a, t_stack *stack_b)
{
	int		size;

	size = stack_a->size / 2;
	while (stack_a->size > size)
	{
		if ((stack_a->head->nb != find_biggest(stack_a->head)) &&
			(stack_a->head->nb != find_smallest(stack_a->head)) &&
			(stack_a->head->index <= size))
			lst_pop_push(stack_b, stack_a, "pb", 0);
		else
			lst_rotate(stack_a, "ra", 0);
	}
	while (stack_a->size > 3)
	{
		if ((stack_a->head->nb != find_biggest(stack_a->head)) &&
			(stack_a->head->nb != find_smallest(stack_a->head)))
			lst_pop_push(stack_b, stack_a, "pb", 0);
		else
			lst_rotate(stack_a, "ra", 0);
	}
}
