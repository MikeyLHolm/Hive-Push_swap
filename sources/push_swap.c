/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/28 15:17:49 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac < 2)
		exit_error(ER_NOARG);
	// init_options();
	stack_a = parse(ac, av);
	if (is_sorted(stack_a->head))
	{
		// display_stack(stack_a->head, 'A');
		lst_free(stack_a);
		return (0);
	}
	stack_b = init_stack();
	// display_stack(stack_a->head, 'A');
	// display_stack(stack_b->head, 'B');
	sort(stack_a, stack_b);
	is_sorted(stack_a->head);
	// display_stack(stack_a->head, 'A');
	// display_stack(stack_b->head, 'B');
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);
	lst_free(stack_a);
	lst_free(stack_b);
	// while (1);
	return (0);
}
