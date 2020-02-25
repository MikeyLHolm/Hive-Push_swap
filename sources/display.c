/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:00 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/25 15:36:43 by mlindhol         ###   ########.fr       */
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
		ft_printf("%d", lst->nb);
		lst = lst->next;
		while (lst != head)
		{
			ft_printf(" - %d", lst->nb);
			lst = lst->next;
		}
	}
	write(1, " ***\n", 5);
}
