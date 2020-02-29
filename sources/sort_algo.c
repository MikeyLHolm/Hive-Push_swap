/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:28:11 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/29 13:03:05 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void		sort_stacks(t_stack *stack_a, t_stack *stack_b)
// {

// }

// void		rev_sort_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	(void)stack_a;
// 	(void)stack_b;
// 	while (stack_b->head == find_biggest(stack_b->head))
// 		lst_pop_push(stack_a, stack_b, "pa");
	
// 	Index stack
	
// 	move from smallest to bottom.
	
// 	{
// 		if (find_smallest(stack_b->head <= stack_b->size / 2))
// 			lst_rotate(stack_b, "rb", 0);
// 		else
// 			lst_rev_rotate(stack_b, "rrb", 0);
// 	}
// 	while (!is_rev_sorted)
// }

// void		median_push_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		token;
// 	int		median;
// 	t_lst	*tmp;

// 	median = find_median(stack_a);
// 	tmp = stack_a->head->previous;
// 	token = 0;
// 	while (token != 1)
// 	{
// 		token = (tmp == stack_a->head) ? 1 : 0;
// 		if (stack_a->head->nb < median)
// 			lst_pop_push(stack_b, stack_a, "pb");
// 		else
// 			lst_rotate(stack_a, "ra", 0);
// 	}
// }

void		sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	push_b_until_3(stack_a, stack_b);
	ft_printf("SIZE B = %d\n", stack_b->size);
	sort_3(stack_a);
	ft_printf("stack b head = %d\n", stack_b->head->nb);
	next_index(stack_a, stack_b->head->index);
	
	// while (is_sorted(stack_a))
	// {
	// 	check_next_move: distance to top. if < size/2 > rotate, otherwise rev rotate.
	// 		if same move for both A and B > execute both.
	// 	pa
	// }
}
