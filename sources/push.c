/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:01:44 by mlindhol          #+#    #+#             */
/*   Updated: 2020/02/18 12:58:10 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	pa:	push a - take the first element at the top of b and
**		put it at the top of a. Do nothing if b is empty.
**	ie. make b-head >> a-head and del b-head.
*/

void	lst_pop_push(t_stack *dst, t_stack *src)
{
	lst_push(dst, lst_pop(src));
}

/*
**	pb:	push b - take the first element at the top of a and
**		put it at the top of b. Do nothing if a is empty.
*/
