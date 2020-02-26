/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:48:02 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/26 14:00:52 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rev_sort_3(t_stack *stack_b)
{
	if (stack_b->head->nb < stack_b->head->next->nb &&
		stack_b->head->nb > stack_b->head->previous->nb &&
		stack_b->head->previous->nb < stack_b->head->next->nb)
		lst_swap(stack_b, "sb");
	else if (stack_b->head->nb < stack_b->head->next->nb &&
		stack_b->head->nb < stack_b->head->previous->nb &&
		stack_b->head->previous->nb > stack_b->head->next->nb)
	{
		lst_swap(stack_b, "sb");
		lst_rev_rotate(stack_b, "rrb");
	}
	else if (stack_b->head->nb < stack_b->head->next->nb &&
		stack_b->head->nb < stack_b->head->previous->nb &&
		stack_b->head->previous->nb < stack_b->head->next->nb)
		lst_rotate(stack_b, "rb");
	else if (stack_b->head->nb > stack_b->head->next->nb &&
		stack_b->head->nb > stack_b->head->previous->nb &&
		stack_b->head->previous->nb > stack_b->head->next->nb)
	{
		lst_swap(stack_b, "sb");
		lst_rotate(stack_b, "rb");
	}
	else if (!is_rev_sorted(stack_b->head))
		lst_rev_rotate(stack_b, "rrb");
}

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

void		sort_56(t_stack *stack_a, t_stack *stack_b)
{
	int		token;
	int		median;
	t_lst	*tmp;

	median = find_median(stack_a);
	tmp = stack_a->head->previous;
	token = 0;
	while (token != 1)
	{
		token = (tmp == stack_a->head) ? 1 : 0;
		if (stack_a->head->nb < median)
			lst_pop_push(stack_b, stack_a, "pb");
		else
			lst_rotate(stack_a, "ra");
	}
	sort_3(stack_a);
	if (stack_b->size == 2 && !is_rev_sorted(stack_b->head))
		lst_swap(stack_b, "sb");
	else if (stack_b->size == 3 && !is_rev_sorted(stack_b->head))
		rev_sort_3(stack_b);
	lst_pop_push(stack_a, stack_b, "pa");
	lst_pop_push(stack_a, stack_b, "pa");
	if (stack_b->size == 1)
		lst_pop_push(stack_a, stack_b, "pa");
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
	else if (stack_a->size == 5 || stack_a->size == 6)
		sort_56(stack_a, stack_b);
	else if (stack_a->size > 6)
		sort_algo(stack_a, stack_b);
}
