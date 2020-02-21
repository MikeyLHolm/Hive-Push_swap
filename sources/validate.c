/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:26:19 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/21 12:52:24 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	AtoI to handle up to intmax_t.
*/

intmax_t		ft_atoimax(const char *str)
{
	intmax_t	res;
	int			sign;

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

int				ft_isint(char *str)
{
	intmax_t	nbr;
	char		*tmp;

	tmp = str;
	while (*tmp)
	{
		if (tmp[0] == '-' || tmp[0] == '+')
			tmp++;
		if (*tmp > '9' || *tmp < '0')
			exit_error(ER_NOTINT);
		tmp++;
	}
	nbr = ft_atoimax(str);
	if (nbr >= (-2147483647 - 1) && nbr <= 2147483647)
		return (nbr);
	else
		exit_error(ER_NOTINT);
	return (0);
}

/*
**	Checks if int is a duplicate of node value in list.
*/

static void		ft_isdup(t_stack *stack_a, int nb)
{
	int			i;
	t_lst		*tmp;

	i = -1;
	tmp = stack_a->head;
	while (++i < stack_a->size)
	{
		if (nb == tmp->nb)
			exit_error(ER_DUP);
		else
			tmp = tmp->next;
	}
}

/*
**	Parse thru array if input is a string instead multiple arguments.
**	Add arguments to a linked list.
*/

/*
**	Parse thru array if input if input is multiple arguments.
**	Add arguments to a linked list.
*/

static void		validate_array(t_stack *stack_a, int ac, char **av)
{
	int			i;
	int			nb;

	i = 0;
	while (++i < ac)
	{
		nb = ft_isint(av[i]);
		ft_isdup(stack_a, nb);
		lst_add(stack_a, lst_create_node(nb));
	}
}

static void		validate_str(t_stack *stack_a, char *str)
{
	char		**arr;
	int			i;
	int			nb;

	arr = ft_strsplit(str, 32);
	i = -1;
	while (arr[++i])
	{
		nb = ft_isint(arr[i]);
		ft_isdup(stack_a, nb);
		lst_add(stack_a, lst_create_node(nb));
		free(arr[i]);
		arr[i] = NULL;
	}
	ft_strdel(arr);
}	

/*
**	Main parsing function. Creates stack and returns it to main after parsing.
*/

t_stack			*parse(int ac, char **av)
{
	t_stack		*stack_a;

	stack_a = init_stack();
	// multiple strings of arguments too? Perhaps not valid input
	if (ac == 2)
		validate_str(stack_a, av[1]);
	else
		validate_array(stack_a, ac, av);
	return (stack_a);
}
