/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/21 11:06:59 by mlindhol         ###   ########.fr       */
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
	if (is_sorted(stack_a->head))
	{
		display_stack(stack_a->head);
		return (0);
	}
	stack_b = init_stack();
	display_stack(stack_a->head);
	display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// Calc moves to sort> then pick fewest.

	// find_median(stack_a);
	// ft_printf("min value = %d, %d", stack_a->min_value);
	
	// lst_pop_push(stack_b, stack_a);
	// write(1, "pb\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);

	// lst_pop_push(stack_b, stack_a);
	// write(1, "pb\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);

	// lst_swap(stack_a);
	// write(1, "sa\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);

	// lst_rotate(stack_a);
	// write(1, "ra\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);

	// lst_pop_push(stack_a, stack_b);
	// write(1, "pa\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);

	// lst_rotate(stack_a);
	// write(1, "ra\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);
	
	// lst_pop_push(stack_a, stack_b);
	// write(1, "pa\n", 3);
	// display_stack(stack_a->head);
	// display_stack(stack_b->head);
	// is_sorted(stack_a->head);
	
	// ft_printf("Stack size = %d\n", stack_a->size);
	// ft_printf("Stack size = %d\n", stack_b->size);


	// lst_free(stack_a);
	// lst_free(stack_b);
	while (1);
	return (0);
}
