/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:23:30 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 10:13:04 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Checks if stack is sorted in ascending order
*/

int			is_sorted(t_lst *stack)
{
	t_lst	*head;

	head = stack;
	while (stack && stack->next)
	{
		if (stack->next == head)
			break ;
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
**	Checks if stack is sorted in descending order
*/

int			is_rev_sorted(t_lst *stack)
{
	t_lst	*head;

	head = stack;
	while (stack && stack->next)
	{
		if (stack->next == head)
			break ;
		if (stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
**	Finds and returns the node with index = 0.
*/

t_lst		*look_for_izero(t_stack *stack)
{
	t_lst	*current;
	t_lst	*izero;

	current = stack->head;
	izero = NULL;
	while (1)
	{
		if (current->index == 0)
		{
			izero = current;
			break ;
		}
		current = current->next;
	}
	return (izero);
}

/*
**	Finds and returns numeric value of smallest node.
*/

long		find_smallest(t_lst *head)
{
	long	smallest;
	long	tmp;

	smallest = head->nb;
	tmp = head->nb;
	while (head != NULL)
	{
		if (smallest > head->nb)
			smallest = head->nb;
		if (head->next && head->next->nb == tmp)
			return (smallest);
		head = head->next;
	}
	return (smallest);
}

/*
**	Finds and returns numeric value of biggest node.
*/

long		find_biggest(t_lst *head)
{
	long	biggest;
	long	tmp;

	biggest = head->nb;
	tmp = head->nb;
	while (head != NULL)
	{
		if (biggest < head->nb)
			biggest = head->nb;
		if (head->next && head->next->nb == tmp)
			return (biggest);
		head = head->next;
	}
	return (biggest);
}
