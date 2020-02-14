/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:00 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/14 16:16:00 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		display_stack(t_lst *lst)
{
	int		i;
	t_lst	*head;

	i = -1;
	write(1, "------------\nStacks a & b\n\n  ", 29);
	head = lst;
	ft_printf("INT %d\n", lst);
	lst = lst->next;
	while (lst != head)
	{
		ft_printf("INT %d\n", lst);
		lst = lst->next;
	}
	write(1, "  _  _\n  a  b\n------------\n", 27);
}

// void		display_lst(t_push_swap )
