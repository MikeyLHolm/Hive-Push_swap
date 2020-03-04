/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:31:57 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 13:38:41 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Prints defined str to standard error followed by a newline or just Error.
**	To print more specific Errors: remove void(str); and
**	change ft_putendl_fd("Error", 2); to ft_putendl_fd(str, 2);
*/

void		exit_error(const char *str)
{
	(void)str;
	ft_putendl_fd("Error", 2);
	exit(1);
}

void		exit_help(void)
{
	ft_printf(BOLD_WHITE"\n\t\tUsage:\n\n");
	ft_printf(BOLD_CYAN"\tChecker options:\t"BOLD_YELLOW);
	ft_printf("./checker -h -l -v\n"RESET);
	ft_printf(BOLD_CYAN"\tRNG with time:\t\t"BOLD_YELLOW);
	ft_printf("ARG=`ruby -e \"puts (1..100).to_a.shuffle.join(' ')\"` ;");
	ft_printf(" time ./push_swap $ARG\n"RESET);
	ft_printf(BOLD_CYAN"\tabove + moves:\t\t"BOLD_YELLOW);
	ft_printf("ARG=`ruby -e \"puts (1..100).to_a.shuffle.join(' ')\"` ;");
	ft_printf(" time ./push_swap $ARG | wc -l\n"RESET);
	ft_printf(BOLD_CYAN"\tpush_swap + checker:\t"BOLD_YELLOW);
	ft_printf("ARG=\"1 5 2 4 3\"; ./push_swap $ARG | ./checker $ARG\n"RESET);
	ft_printf(BOLD_CYAN"\tExternal Visualizer:\t"BOLD_YELLOW);
	ft_printf("python3 pyviz.py `ruby -e \"puts (1..100)");
	ft_printf(".to_a.shuffle.join(' ')\"`"RESET);
	ft_printf(BOLD_WHITE"\n\n\t\tChange numbers (1..100 or 1 5 2 4 3) ");
	ft_printf("for different input"RESET"\n\n");
	exit(1);
}
