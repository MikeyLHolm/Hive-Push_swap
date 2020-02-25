/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:53 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 09:44:08 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	sa/sb:	swap a/b - swap the first 2 elements at the top of stack a/b.
**			Do nothing if there is only one or no elements.
*/

void		lst_swap(t_stack *stack, char *str)
{
	t_lst		*tmp;

	if (stack->head && stack->head->next != stack->head)
	{
		tmp = stack->head;
		stack->head->next->previous = stack->head->previous;
		stack->head->previous->next = stack->head->next;
		stack->head = stack->head->next;
		tmp->next = stack->head->next;
		tmp->previous = stack->head;
		stack->head->next->previous = tmp;
		stack->head->next = tmp;
		ft_printf("%s\n", str);
	}
}

/*
**	ss:	sa and sb at the same time.
*/

void		lst_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n   ");
	lst_swap(stack_a, "sa");
	ft_printf("   ");
	lst_swap(stack_b, "sb");
}
