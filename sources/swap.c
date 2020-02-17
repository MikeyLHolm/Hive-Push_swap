/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:53 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/17 17:11:36 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	sa:	swap a - swap the first 2 elements at the top of stack a. 
**		Do nothing if there is only one or no elements.
*/

t_stack		*sa(t_stack *stack_a)
{
	t_lst		*tmp;
	t_lst		*prev;
	t_lst		*follow;

	if (stack_a->head && stack_a->head->next)
	{
		tmp = stack_a->head;
		follow = stack_a->head->next->next;
		prev = stack_a->head->previous;
		stack_a->head = stack_a->head->next;
		stack_a->head->next = tmp;
		stack_a->head->next->next = follow;
		stack_a->head->previous = prev;
	}
	return (stack_a);
}

/*
**	sb:	swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there is only one or no elements.
*/

void	sb(t_stack *stack_b)
{
	t_lst		*tmp;

	if (stack_b->head && stack_b->head->next)
	{
		tmp = stack_b->head;
		stack_b->head = stack_b->head->next;
		stack_b->head->next = tmp;
	}
}

/*
**	ss:	sa and sb at the same time.
*/

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
