/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:51:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/21 16:08:07 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
** Error handling: args not int, args > int, duplicates, 
**				   instruction dont exist, incorrect formating
**
**
**
**
**
*/

void	checker(int ac, char **av)
{
	char		*line;
	int			ret;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = parse(ac, av);
	while (get_next_line(0, &line) > 0)
	{
		line...
	}
	if (ret < 0)
		exit_error(ER_GNL);
	if (is_sorted(stack_a->head && stack_b->head == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		main(int ac, char **av)
{


	if (ac > 1)
		checker(ac, av);
	return (0);
}