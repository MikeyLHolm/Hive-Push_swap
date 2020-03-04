/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:26:12 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 13:38:54 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack			*init_stack(void)
{
	t_stack		*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit_error(ER_MALLOC);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

t_options		*init_options(void)
{
	t_options	*options;

	if (!(options = (t_options *)malloc(sizeof(t_options))))
		exit_error(ER_MALLOC);
	options->help = 0;
	options->moves = 0;
	options->verbose = 0;
	return (options);
}
