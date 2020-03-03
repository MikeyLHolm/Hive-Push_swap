/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:28:11 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/03 17:49:47 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_direction(t_stack *stack, t_lst *node)
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
		return (-1);
	return (1);
}

t_lst		*find_next_move(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min_moves;
	int		moves;
	t_lst	*current;
	t_lst	*next_move;

	i = -1;
	min_moves = 999999;
	current = stack_b->head;
	next_move = NULL;
	while (++i < stack_b->size)
	{
		moves = distance_to_top(stack_b, current) +
				distance_to_top(stack_a, next_index(stack_a, current->index));
		if (moves < min_moves ||
			(moves == min_moves && distance_to_top(stack_b, current) > 0
		&& distance_to_top(stack_a, next_index(stack_a, current->index)) > 0))
		{
			min_moves = moves;
			next_move = current;
		}
		current = current->next;
	}
	return (next_move);
}

void		execute_move(t_stack *stack_a, t_stack *stack_b, t_lst *next_move)
{
	int		dir_a;
	int		dir_b;
	t_lst	*a;

	dir_a = 0;
	dir_b = 0;
	a = next_index(stack_a, next_move->index);
	while ((distance_to_top(stack_a, a) > 0 || distance_to_top(stack_b, next_move) > 0))
	{
		if (distance_to_top(stack_a, a) > 0)
			dir_a = check_direction(stack_a, a);
		if (distance_to_top(stack_b, next_move) > 0)
			dir_b = check_direction(stack_b, next_move);
		if (dir_a == 1 && dir_b == 1)
		{
			dir_a = 0;
			dir_b = 0;
			lst_rr(stack_a, stack_b, 0);
		}
		else if (dir_a == -1 && dir_b == -1)
		{
			dir_a = 0;
			dir_b = 0;
			lst_rrr(stack_a, stack_b, 0);
		}
		if (dir_a == 1 && dir_b != 1)
			lst_rotate(stack_a, "ra", 0);
		else if (dir_a == -1 && dir_b != -1)
			lst_rev_rotate(stack_a, "rra", 0);
		if (dir_b == 1 && dir_a != 1)
			lst_rotate(stack_b, "rb", 0);
		else if (dir_b == -1 && dir_a != -1)
			lst_rev_rotate(stack_b, "rrb", 0);
	}
}

void		sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*next_move;

	push_b_until_3(stack_a, stack_b);
	sort_3(stack_a);
	while (stack_b->size > 0)
	{
		next_move = find_next_move(stack_a, stack_b);
		execute_move(stack_a, stack_b, next_move);
		lst_pop_push(stack_a, stack_b, "pa", 0);
	}
	if (!is_sorted(stack_a->head))
	{
		if (check_direction(stack_a, look_for_izero(stack_a)) > 0)
			while (!is_sorted(stack_a->head))
				lst_rotate(stack_a, "ra", 0);
		else if (check_direction(stack_a, look_for_izero(stack_a)) < 0)
			while (!is_sorted(stack_a->head))
				lst_rev_rotate(stack_a, "rra", 0);
	}
}
