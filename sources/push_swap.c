/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/13 14:30:29 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_push_swap		data;

	if (ac < 2)
		exit_error(ER_NOARG);
	if(!(data.stack_a = (t_stack *)malloc(sizeof(t_stack))))
		exit_error(ER_MALLOC);
	data.stack_a->lst = NULL;
	validate(&data.stack_a->lst, ac, av);
	display_stack(data.stack_a->lst);
	// free(data);
	free(data.stack_a);
	// while (1);
	return (0);
}
