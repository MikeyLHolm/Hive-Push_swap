/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:51:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/26 16:36:54 by mlindhol         ###   ########.fr       */
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

int		pw_is_line_valid(const char *line)
{
	if (ft_strequ(line, "sa"))
		return (1);
	else if (ft_strequ(line, "sb"))
		return (1);
	else if (ft_strequ(line, "ss"))
		return (1);
	else if (ft_strequ(line, "pa"))
		return (1);
	else if (ft_strequ(line, "pb"))
		return (1);
	else if (ft_strequ(line, "ra"))
		return (1);
	else if (ft_strequ(line, "rb"))
		return (1);
	else if (ft_strequ(line, "rr"))
		return (1);
	else if (ft_strequ(line, "rra"))
		return (1);
	else if (ft_strequ(line, "rrb"))
		return (1);
	else if (ft_strequ(line, "rrr"))
		return (1);
	else
		return (0);
}

void	checker(int ac, char **av)
{
	char		*line;
	int			ret;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_b = init_stack();
	stack_a = parse(ac, av);
	while (get_next_line(0, &line) > 0)
	{
		
		free(line);
	}
	if (ret < 0)
		exit_error(ER_GNL);
	if (is_sorted(stack_a->head) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_free(stack_a);
	lst_free(stack_b);
}

int		main(int ac, char **av)
{


	if (ac > 1)
		checker(ac, av);
	return (0);
}