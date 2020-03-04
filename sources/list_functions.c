/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:25:16 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 08:34:06 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Create node and init attributes.
*/

t_lst		*lst_create_node(int nb)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		exit_error(ER_MALLOC);
	node->index = -1;
	node->nb = nb;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

/*
**	Add parameter given node to a stack (doubly linked list)
*/

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

/*
**	Insert node on top of the stack.
*/

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

/*
**	Remove node from top of the stack.
*/

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

/*
**	Free stack and each node inside it.
*/

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
