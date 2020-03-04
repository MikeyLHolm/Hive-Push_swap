/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:49:00 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 13:29:45 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Placeholder display function.
*/

void		display_stack(t_lst *lst, char c)
{
	t_lst	*head;

	ft_printf(BOLD_MAGENTA"\n*** Stack %c: <> "RESET, c);
	if (lst)
	{
		head = lst;
		ft_printf(BOLD_GREEN"%d"RESET, lst->nb);
		ft_printf(BOLD_MAGENTA" <> "RESET);
		lst = lst->next;
		while (lst != head)
		{
			ft_printf(BOLD_GREEN"%d"RESET, lst->nb);
			lst = lst->next;
			if (lst != head)
				ft_printf(BOLD_MAGENTA" <> "RESET);
		}
	}
	ft_printf(BOLD_MAGENTA" <> ***\n"RESET);
}
