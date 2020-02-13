/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:26:19 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/13 15:51:15 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*
**	AtoI to handle up to intmax_t.
*/

intmax_t		ft_atoimax(const char *str)
{
	intmax_t		res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str && (*str == '\r' || *str == '\n' || *str == '\t' ||
					*str == '\f' || *str == '\v' || *str == ' '))
		str++;
	if (str[0] == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

/*
**	Check if input is int.
*/

// CHECK MINUSES!!!

// int				ft_isint(char *str)
// {
// 	intmax_t		nbr;
// 	char			*tmp;

// 	tmp = str;
// 	while (*tmp)
// 	{
// 		if (*tmp > '9' || *tmp < '0')
// 			exit_error (ER_NOTINT);
// 		tmp++;
// 	}
// 	nbr = ft_atoimax(str);
// 	// printf("NBR IS %jd\n", nbr);
// 	if (nbr >= (-2147483647 - 1) && nbr <= 2147483647)
// 		return (nbr);
// 	else
// 		exit_error(ER_NOTINT);
// 	return (0);
// }

// /*
// **	Validating input before adding to int array. Checks duplicates and if int.
// */

// static int		validator(char *str, int *stack_a, int len)
// {
// 	int		i;
// 	int		nbr;

// 	nbr = ft_isint(str);
// 	i = -1;
// 	while (++i < len)
// 	{
// 		if (nbr == stack_a[i])
// 			exit_error(ER_DUP);
// 	}
// 	return (nbr);
// }

/*
**	Creating the stack and inputing variables if valid.
*/

void				validate(t_lst **lst, int ac, char **av)
{
	int				i;
	
	i = 0;

	*lst = lst_add_append(*lst, ft_atoimax(av[1]));
	ac = 2;
	// while (++i < ac)
	// {
	// 	if (i == 1)
	// 	{
	// 		lst_add_append() = ft_isint(av[i++]);
	// 		if (ac == 2)
	// 			return (stack_a);
	// 	}
	// 	stack_a[i - 1] = validator(av[i], stack_a, i - 1);
	// }
}
