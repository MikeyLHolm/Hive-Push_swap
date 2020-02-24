/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:48:02 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/24 17:09:29 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_2(t_stack *stack_a)
{
	if (stack_a->head->nb > stack_a->head->next->nb)
		lst_swap(stack_a);
}

void		sort_3(t_stack *stack_a)
{
	if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb < stack_a->head->previous->nb &&
		stack_a->head->previous->nb > stack_a->head->next->nb)
		lst_swap(stack_a);
	else if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb > stack_a->head->previous->nb &&
		stack_a->head->previous->nb < stack_a->head->next->nb)
	{
		lst_swap(stack_a);
		lst_rev_rotate(stack_a);
	}
	else if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb > stack_a->head->previous->nb &&
		stack_a->head->previous->nb > stack_a->head->next->nb)
		lst_rotate(stack_a);
	else if (stack_a->head->nb < stack_a->head->next->nb &&
		stack_a->head->nb < stack_a->head->previous->nb &&
		stack_a->head->previous->nb < stack_a->head->next->nb)
	{
		lst_swap(stack_a);
		lst_rotate(stack_a);
	}
	else
		lst_rev_rotate(stack_a);
}

void		sort_4(t_stack *stack_a, t_stack *stack_b)
{
	lst_pop_push(stack_b, stack_a);
	sort_3(stack_a);
	
}

void		sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_b);
	
}