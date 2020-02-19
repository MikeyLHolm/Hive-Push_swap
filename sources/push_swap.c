/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/18 09:29:36 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac < 2)
		exit_error(ER_NOARG);
	stack_a = parse(ac, av);
	stack_b = init_stack();
	display_stack(stack_a->head);
	ft_printf("Stack size = %d\n", stack_a->size);
	// Calc moves to sort> then pick fewest.

/*	sort>
	sort(stack_a, stack_b)
*/
	stack_a = lst_swap(stack_a);
	display_stack(stack_a->head);
	ft_printf("Stack size = %d\n", stack_a->size);
	// lst_free(stack_a);
	lst_free(stack_b);
	// while (1);
	return (0);
}
