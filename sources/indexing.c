/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:49:03 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/02 14:36:42 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Find next index of a elem in A for elem in B.
**		ie. find which index to bring to top of stack A.
*/

t_lst				*next_index(t_stack *stack, int index)
{
	int				i;
	t_lst			*next_i;
	t_lst			*current;

	i = -1;
	next_i = NULL;
	current = stack->head;
	while (++i < stack->size && next_i == NULL)
	{
		if (current->index > index)
			next_i = current;
		current = current->next;
	}
	while (i++ < stack->size)
	{
		if (index + 1 == next_i->index)
			return (next_i);
		if (index < current->index && current->index < next_i->index)
			next_i = current;
		current = current->next;
	}
	return (next_i);
}

/*
**	Finds the smallest number of the stack that has index of -1.
*/

t_lst				*find_next_smallest(t_stack *stack)
{
	int				i;
	int				min;
	t_lst			*current;
	t_lst			*smallest;

	smallest = NULL;
	if (stack)
	{
		i = -1;
		min = 0;
		current = stack->head;
		while (++i < stack->size)
		{
			if ((current->index == -1) && (!min || current->nb < smallest->nb))
			{
				min = 1;
				smallest = current;
			}
			current = current->next;
		}
	}
	return (smallest);
}

/*
**	Indices the stack from smallest to biggest.
*/

void				index_stack(t_stack *stack)
{
	int				i;
	t_lst			*current;

	i = -1;
	while ((current = find_next_smallest(stack)))
		current->index = ++i;
}
