/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:42:26 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 16:28:41 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				distance_to_top(t_stack *stack, t_lst *node)
{
	int			operations;
	t_lst		*current;

	operations = -1;
	current = stack->head;
	while (++operations < stack->size)
	{
		if (node == current)
			break ;
		current = current->next;
	}
	if (operations > stack->size / 2)
	{
		operations = 0;
		current = stack->head;
		while (stack)
		{
			if (node == current)
				break ;
			++operations;
			current = current->previous;
		}
	}
	return (operations);
}

/*
**	If nb is < median RA, otherwise RRA.
*/






int				choose_pa_index(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			moves;
	int			least_moves;
	int			best_i;
	t_lst		*current;
	t_lst		*b_current;

	b_current = stack_b->head;
	moves = distance_to_top(stack_a, current) + distance_to_top(stack_b, b_current);
	if (moves < least_moves)
		best_i = b_current->index;
	return (i);
}