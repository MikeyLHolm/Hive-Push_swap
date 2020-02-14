/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/14 11:07:13 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*stack_a;

	if (ac < 2)
		exit_error(ER_NOARG);
	stack_a = parse(ac, av);
	// stack_a = validate;
	// if(!(data.stack_a = (t_stack *)malloc(sizeof(t_stack))))
	// 	exit_error(ER_MALLOC);
	// data.stack_a->lst = NULL;
	// validate(&data.stack_a->lst, ac, av);
	display_stack(stack_a->head);
	// free(data);
	// free(stack_a);
	// while (1);
	return (0);
}
