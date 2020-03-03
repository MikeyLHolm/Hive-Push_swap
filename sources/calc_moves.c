/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:42:26 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/03 09:40:00 by mlindhol         ###   ########.fr       */
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
