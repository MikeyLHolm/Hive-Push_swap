/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:00 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/17 17:07:34 by mlindhol         ###   ########.fr       */
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
	if (lst->nb < 0)
			ft_printf("%d\n", lst->nb);
		else
			ft_printf(" %d\n", lst->nb);
	lst = lst->next;
	while (lst != head)
	{
		if (lst->nb < 0)
			ft_printf("  %d\n", lst->nb);
		else
			ft_printf("   %d\n", lst->nb);
		lst = lst->next;
	}
	write(1, "   _   _\n   a   b\n------------\n", 31);
}

// void		display_lst(t_push_swap )
