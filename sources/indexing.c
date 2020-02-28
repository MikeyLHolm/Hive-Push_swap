/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:49:03 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 09:16:48 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if ((current->index = -1) &&
				(min == 0 || current->nb < smallest->nb))
			{
				min = 1;
				smallest = current;
			}
			current = current->next;
		}
	}
	return (smallest);	
}

void				index_stack(t_stack *stack)
{
	int				index;
	t_lst			*current;

	index = 0;
	while ((current = find_next_smallest(stack)))
		current->index = index++;
}
