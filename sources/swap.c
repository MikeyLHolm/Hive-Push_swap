/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:53 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/19 09:52:13 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	sa/sb:	swap a/b - swap the first 2 elements at the top of stack a/b.
**			Do nothing if there is only one or no elements.
*/

void		lst_swap(t_stack *stack)
{
	t_lst		*tail;
	t_lst		*first;
	t_lst		*second;
	t_lst		*third;

	if (stack->head && stack->head->next)
	{
		first = stack->head;
		second = first->next;
		third = second->next;
		tail = first->previous;
		second->next = first;
		second->previous = tail;
		tail->next = second;
		first->next = third;
		first->previous = second;
		third->previous = first;
		stack->head = second;
	}
}

/*
**	ss:	sa and sb at the same time.
*/

void		lst_ss(t_stack *stack_a, t_stack *stack_b)
{
	lst_swap(stack_a);
	lst_swap(stack_b);
}
