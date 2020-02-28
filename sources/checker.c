/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:51:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/27 14:51:33 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Compares read command and executes the right command.
*/

void		run_command(t_stack *stack_a, t_stack *stack_b, const char *line)
{
	if (ft_strequ(line, "sa"))
		lst_swap(stack_a, "sa", 0);
	else if (ft_strequ(line, "sb"))
		lst_swap(stack_b, "sb", 0);
	else if (ft_strequ(line, "ss"))
		lst_ss(stack_a, stack_b);
	else if (ft_strequ(line, "pa"))
		lst_pop_push(stack_a, stack_b, "pa");
	else if (ft_strequ(line, "pb"))
		lst_pop_push(stack_b, stack_a, "pb");
	else if (ft_strequ(line, "ra"))
		lst_rotate(stack_a, "ra", 0);
	else if (ft_strequ(line, "rb"))
		lst_rotate(stack_b, "rb", 0);
	else if (ft_strequ(line, "rr"))
		lst_rr(stack_a, stack_b);
	else if (ft_strequ(line, "rra"))
		lst_rev_rotate(stack_a, "rra", 0);
	else if (ft_strequ(line, "rrb"))
		lst_rev_rotate(stack_b, "rrb", 0);
	else if (ft_strequ(line, "rrr"))
		lst_rrr(stack_a, stack_b);
	else
		exit_error(ER_CMD);
}

/*
**	Checker function to create and validate stacks & read and run the commands.
*/

void		checker(int ac, char **av)
{
	char		*line;
	int			ret;
	int			moves;
	t_stack		*stack_a;
	t_stack		*stack_b;

	moves = 0;
	ret = 0;
	stack_b = init_stack();
	stack_a = parse(ac, av);
	while (get_next_line(0, &line) > 0)
	{
		run_command(stack_a, stack_b, line);
		moves++;
		free(line);
	}
	if (ret < 0)
		exit_error(ER_GNL);
	if (is_sorted(stack_a->head) && stack_b->size == 0)
		ft_printf(BOLD_GREEN"OK\n"RESET);
	else
		ft_printf(BOLD_RED"KO\n"RESET);
	ft_printf(BOLD_YELLOW"%d\n"RESET, moves);
	lst_free(stack_a);
	lst_free(stack_b);
}

/*
**	Main to start Checker.
*/

int			main(int ac, char **av)
{
	if (ac > 1)
		checker(ac, av);
	return (0);
}
