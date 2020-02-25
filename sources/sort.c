/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:48:02 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 16:00:13 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_3(t_stack *stack_a)
{
	if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb < stack_a->head->previous->nb &&
		stack_a->head->previous->nb > stack_a->head->next->nb)
		lst_swap(stack_a, "sa");
	else if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb > stack_a->head->previous->nb &&
		stack_a->head->previous->nb < stack_a->head->next->nb)
	{
		lst_swap(stack_a, "sa");
		lst_rev_rotate(stack_a, "rra");
	}
	else if (stack_a->head->nb > stack_a->head->next->nb &&
		stack_a->head->nb > stack_a->head->previous->nb &&
		stack_a->head->previous->nb > stack_a->head->next->nb)
		lst_rotate(stack_a, "ra");
	else if (stack_a->head->nb < stack_a->head->next->nb &&
		stack_a->head->nb < stack_a->head->previous->nb &&
		stack_a->head->previous->nb < stack_a->head->next->nb)
	{
		lst_swap(stack_a, "sa");
		lst_rotate(stack_a, "ra");
	}
	else if (!is_sorted(stack_a->head))
		lst_rev_rotate(stack_a, "rra");
}

void		sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;

	tmp = stack_b->head->nb;
	if (tmp < stack_a->head->nb)
		lst_pop_push(stack_a, stack_b, "pa");
	else if (tmp > stack_a->head->nb && tmp < stack_a->head->next->nb)
	{
		lst_rotate(stack_a, "ra");
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rev_rotate(stack_a, "rra");
	}
	else if (tmp < stack_a->head->previous->nb && tmp > stack_a->head->next->nb)
	{
		lst_rev_rotate(stack_a, "rra");
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rotate(stack_a, "ra");
		lst_rotate(stack_a, "ra");
	}
	else if (tmp > stack_a->head->previous->nb)
	{
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rotate(stack_a, "ra");
	}
}

void		sort_5_2(t_stack *stack_a, t_stack *stack_b, int token)
{
	if (token == 1)
	{
		lst_rotate(stack_a, "ra");
		lst_rotate(stack_a, "ra");
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rev_rotate(stack_a, "rra");
		lst_rev_rotate(stack_a, "rra");
	}
	else if (token == 2)
	{
		lst_rev_rotate(stack_a, "rra");
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rotate(stack_a, "ra");
		lst_rotate(stack_a, "ra");
	}
}

void		sort_5(t_stack *stack_a, t_stack *stack_b)
{
	lst_pop_push(stack_b, stack_a, "pb");
	lst_pop_push(stack_b, stack_a, "pb");
	sort_3(stack_a);
	sort_4(stack_a, stack_b);
	if (stack_b->head->nb < find_smallest(stack_a->head))
		lst_pop_push(stack_a, stack_b, "pa");
	else if (stack_b->head->nb > stack_a->head->nb &&
			stack_b->head->nb < stack_a->head->next->nb)
	{
		lst_pop_push(stack_a, stack_b, "pa");
		lst_swap(stack_a, "sa");
	}
	else if (stack_b->head->nb > stack_a->head->next->nb &&
			stack_b->head->nb < stack_a->head->next->next->nb)
		sort_5_2(stack_a, stack_b, 1);
	else if (stack_b->head->nb > stack_a->head->next->next->nb &&
			stack_b->head->nb < stack_a->head->previous->nb)
		sort_5_2(stack_a, stack_b, 2);
	else if (stack_b->head->nb > find_biggest(stack_a->head))
	{
		lst_pop_push(stack_a, stack_b, "pa");
		lst_rotate(stack_a, "ra");
	}
}

void		sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->nb > stack_a->head->next->nb)
			lst_swap(stack_a, "sa");
	}
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
	{
		lst_pop_push(stack_b, stack_a, "pb");
		sort_3(stack_a);
		sort_4(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort_algo(stack_a, stack_b);
}
