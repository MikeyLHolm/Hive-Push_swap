/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:10 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 11:51:50 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Main PS function to call sorting etc.
*/

int			main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac < 2)
		exit_error(ER_NOARG);
	stack_a = parse(ac, av);
	if (is_sorted(stack_a->head))
	{
		lst_free(stack_a);
		return (0);
	}
	stack_b = init_stack();
	sort(stack_a, stack_b);
	lst_free(stack_a);
	lst_free(stack_b);
	return (0);
}
