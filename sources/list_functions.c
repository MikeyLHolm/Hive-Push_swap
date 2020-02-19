/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:25:16 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/19 11:37:02 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Add new nodes to the list. ADD PREVIOUS CHECK??
*/

t_lst		*lst_create_node(int nb)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		exit_error(ER_MALLOC);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

void		lst_add(t_stack *stack, t_lst *node)
{
	t_lst		*tail;

	if (stack && node)
	{
		if (!stack->head)
		{
			stack->head = node;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			node->previous = tail;
			tail->next = node;
			node->next = stack->head;
			stack->head->previous = node;
		}
		stack->size++;
	}
}

void		lst_push(t_stack *stack, t_lst *node)
{
	t_lst		*tail;

	if (stack && node)
	{
		if (!stack->head)
		{
			stack->head = node;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			node->previous = tail;
			tail->next = node;
			node->next = stack->head;
			stack->head->previous = node;
			stack->head = node;
		}
		stack->size++;
	}
}

t_lst		*lst_pop(t_stack *stack)
{
	t_lst	*tmp;

	tmp = NULL;
	if (stack->head)
	{
		if (stack->size == 1)
		{
			tmp = stack->head;
			stack->head = NULL;
			tmp->previous = NULL;
			tmp->next = NULL;
		}
		else
		{
			tmp = stack->head;
			stack->head = stack->head->next;
			tmp->next->previous = tmp->previous;
			tmp->previous->next = tmp->next;
			tmp->next = NULL;
			tmp->previous = NULL;
		}
	}
	--stack->size;
	return (tmp);
}

void		lst_free(t_stack *stack)
{
	int		i;
	t_lst	*current;
	t_lst	*tmp;

	i = -1;
	current = stack->head;
	while (++i < stack->size)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
}

/*
t_lst		*lst_prepend(t_lst *head, t_lst *node)
{
	if (!head)
		return (node);
	node->next = head;
	return (node);
}

t_lst		*lst_append(t_lst *head, t_lst *node)
{
	t_lst		*current;

	if (!head)
		return (node);
	current = head;
	while (current->next)
		current = current->next;
	current->next = node;
	return (head);
}

t_lst	*lst_create_append(t_lst *head, int nb)
{
	t_lst *node;

	node = lst_create_node(nb);
	return (lst_prepend(head, node));
}

t_lst	*lst_create_prepend(t_lst *head, int nb)
{
	t_lst *node;

	node = lst_create_node(nb);
	return (lst_append(head, node));
}
*/
