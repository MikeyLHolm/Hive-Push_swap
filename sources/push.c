/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/17 11:38:54 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	pa:	push a - take the first element at the top of b and put it at the top of a. 
**		Do nothing if b is empty.
**	ie. make b-head >> a-head and del b-head.
*/

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*tmp;

	if (stack_b->head)
	{
		tmp = stack_a->head;
		lst_add(stack_a, stack_b->head);
		stack_b->head = stack_b->head->next;
		
	}
}

/*
**	pb:	push b - take the first element at the top of a and put it at the top of b.
**		Do nothing if a is empty.
*/
