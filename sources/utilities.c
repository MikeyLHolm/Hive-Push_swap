/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:23:30 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 15:59:38 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_lst *stack)
{
	t_lst	*head;

	head = stack;
	while (stack && stack->next)
	{
		if (stack->next == head)
			break ;
		if (stack->nb > stack->next->nb)
		{
			write(1, "NOT SORTED\n", 11);
			return (0);
		}
		stack = stack->next;
	}
	write(1, "SORTED\n", 7);
	return (1);
}

int			is_rev_sorted(t_lst *stack)
{
	t_lst	*head;

	head = stack;
	while (stack && stack->next)
	{
		if (stack->next == head)
			break ;
		if (stack->nb < stack->next->nb)
		{
			write(1, "NOT SORTED\n", 11);
			return (0);
		}
		stack = stack->next;
	}
	write(1, "REVERSE SORTED\n", 15);
	return (1);
}

t_lst		*next_index(t_stack *stack)
{
	int		i;
	t_lst	*tmp;
	t_lst	*min;

	i = -1;
	min = NULL;
	tmp = stack->head;
	if (stack)
	{
		while (++i < stack->size)
		{
			if (!min)
			{
				stack->min_value = tmp->nb;
				min = tmp;
				tmp = tmp->next;
			}
			else
			{
				if (!stack->head->index && stack->min_value > tmp->nb)
				{
					stack->min_value = tmp->nb;
					min = tmp;
				}
				tmp = tmp->next;
			}
		}
	}
	return (min);
}

long		find_smallest(t_lst *head)
{
	int		smallest;
	int		tmp;

	smallest = head->nb;
	tmp = head->nb;
	while (head != NULL)
	{
		if (smallest > head->nb)
			smallest = head->nb;
		if (head->next && head->next->nb != tmp)
			break ;
		head = head->next;
	}
	return (smallest);
}

long		find_biggest(t_lst *head)
{
	int		biggest;
	int		tmp;

	biggest = head->nb;
	tmp = head->nb;
	while (head != NULL)
	{
		if (biggest < head->nb)
			biggest = head->nb;
		if (head->next && head->next->nb != tmp)
			break ;
		head = head->next;
	}
	return (biggest);
}

void		find_median(t_stack *stack)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	while ((tmp = next_index(stack)))
		tmp->index = i++;
}
