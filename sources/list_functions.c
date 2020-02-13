/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:25:16 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/13 13:14:13 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Add new nodes to the list. ADD PREVIOUS CHECK??
*/

t_lst		*lst_add(int nb)
{
	t_lst		*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		exit_error(ER_MALLOC);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

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

t_lst	*lst_add_append(t_lst *head, int nb)
{
	t_lst *node;

	node = lst_add(nb);
	return (lst_prepend(head, node));
}

t_lst	*lst_add_prepend(t_lst *head, int nb)
{
	t_lst *node;

	node = lst_add(nb);
	return (lst_append(head, node));
}