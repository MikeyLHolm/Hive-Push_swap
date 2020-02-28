/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:49:03 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 15:17:15 by mlindhol         ###   ########.fr       */
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
			if ((current->index == -1) && (!min || current->nb < smallest->nb))
			{
				min = 1;
				smallest = current;
			}
			current = current->next;
		}
	}
	ft_printf("Hello\n");
	return (smallest);
}

void				index_stack(t_stack *stack)
{
	int				i;
	t_lst			*current;

	i = -1;
	while ((current = find_next_smallest(stack)))
		current->index = ++i;
}
