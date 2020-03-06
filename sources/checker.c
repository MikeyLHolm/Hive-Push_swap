/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:51:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 14:10:49 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		check_options(t_stack *stack_a, t_stack *stack_b,
									t_options *options, int moves)
{
	if (options->verbose)
	{
		ft_printf(BOLD_MAGENTA"_______________________________________\n"RESET);
		display_stack(stack_a->head, 'A');
		ft_printf(BOLD_MAGENTA"_______________________________________\n"RESET);
		display_stack(stack_b->head, 'B');
		ft_printf(BOLD_MAGENTA"_______________________________________\n"RESET);
		write(1, "\n", 1);
	}
	if (options->moves)
		ft_printf(BOLD_YELLOW"Operations: [ %d ]\n"RESET, moves);
}

/*
** Compares read command and executes the right command.
*/

static void		run_cmd(t_stack *stack_a, t_stack *stack_b, const char *line)
{
	if (ft_strequ(line, "sa"))
		lst_swap(stack_a, "sa", 1);
	else if (ft_strequ(line, "sb"))
		lst_swap(stack_b, "sb", 1);
	else if (ft_strequ(line, "ss"))
		lst_ss(stack_a, stack_b, 1);
	else if (ft_strequ(line, "pa"))
		lst_pop_push(stack_a, stack_b, "pa", 1);
	else if (ft_strequ(line, "pb"))
		lst_pop_push(stack_b, stack_a, "pb", 1);
	else if (ft_strequ(line, "ra"))
		lst_rotate(stack_a, "ra", 1);
	else if (ft_strequ(line, "rb"))
		lst_rotate(stack_b, "rb", 1);
	else if (ft_strequ(line, "rr"))
		lst_rr(stack_a, stack_b, 1);
	else if (ft_strequ(line, "rra"))
		lst_rev_rotate(stack_a, "rra", 1);
	else if (ft_strequ(line, "rrb"))
		lst_rev_rotate(stack_b, "rrb", 1);
	else if (ft_strequ(line, "rrr"))
		lst_rrr(stack_a, stack_b, 1);
	else
		exit_error(ER_CMD);
}

/*
**	Checker function to create and validate stacks & read and run the commands.
*/

static void		checker(int ac, char **av, t_options *options)
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
		run_cmd(stack_a, stack_b, line);
		moves++;
		free(line);
	}
	if (ret < 0)
		exit_error(ER_GNL);
	check_options(stack_a, stack_b, options, moves);
	if (is_sorted(stack_a->head) && stack_b->size == 0)
		ft_printf(BOLD_GREEN"OK\n"RESET);
	else
		ft_printf(BOLD_RED"KO\n"RESET);
	lst_free(stack_a);
	lst_free(stack_b);
}

/*
**	Main to start Checker.
*/

int				main(int ac, char **av)
{
	t_options	*options;

	options = init_options();
	while (ac > 1 && (!ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "-l") ||
			!ft_strcmp(av[1], "-v")))
	{
		if (!ft_strcmp(av[1], "-h"))
			options->help = 1;
		else if (!ft_strcmp(av[1], "-l"))
			options->moves = 1;
		else if (!ft_strcmp(av[1], "-v"))
			options->verbose = 1;
		++av;
		--ac;
	}
	if (ac > 1 && !options->help)
		checker(ac, av, options);
	else if (options->help)
		exit_help();
	free(options);
	return (0);
}
