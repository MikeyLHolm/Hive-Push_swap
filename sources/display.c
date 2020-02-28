/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:00 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 14:38:56 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		display_stack(t_lst *lst, char c)
{
	t_lst	*head;

	ft_printf("*** Stack %c: ", c);
	if (lst)
	{
		head = lst;
		ft_printf("%d, %d", lst->nb, lst->index);
		lst = lst->next;
		while (lst != head)
		{
			ft_printf(" <> %d, %d", lst->nb, lst->index);
			lst = lst->next;
		}
	}
	write(1, " ***\n", 5);
}
