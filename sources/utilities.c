/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:23:30 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 14:21:49 by mlindhol         ###   ########.fr       */
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
			return (0);
		stack = stack->next;
	}
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
			return (0);
		stack = stack->next;
	}
	return (1);
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

// long		find_next_smallest(t_lst *head)
// {
// 	int		smallest;
// 	int		tmp;

// 	smallest = head->nb;
// 	tmp = head->nb;
// 	while (head != NULL)
// 	{
// 		if (smallest > head->nb)
// 			smallest = head->nb;
// 		if (head->next && head->next->nb != tmp)
// 			break ;
// 		head = head->next;
// 	}
// 	return (smallest);
// }

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
