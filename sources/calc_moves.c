/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:42:26 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 10:07:31 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Calculates node's distance to top of the stack.
*/

int				dist_to_top(t_stack *stack, t_lst *node)
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
