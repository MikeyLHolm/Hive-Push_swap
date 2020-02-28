/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:31:57 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/27 15:51:17 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Prints defined str to standard error followed by a newline.
*/

void		exit_error(const char *str)
{
	// ft_putendl_fd(str, 2);
	ft_putendl_fd("Error", 2);
	exit(1);
}
