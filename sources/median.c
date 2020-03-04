/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:39:46 by mlindhol          #+#    #+#             */
/*   Updated: 2020/03/04 10:10:31 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Sorting helper for find_median.
*/

static void		sort_array(long *array, int len)
{
	long		tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

/*
**	Finds median of the stack and returns the nb value of it.
*/

int				find_median(t_stack *stack)
{
	long		*array;
	int			i;
	int			len;
	int			median;

	len = stack->size;
	if (!(array = (long *)malloc(sizeof(long) * len)))
		exit_error(ER_MALLOC);
	i = -1;
	while (++i < len)
	{
		array[i] = stack->head->nb;
		stack->head = stack->head->next;
	}
	sort_array(array, len);
	median = array[len / 2];
	free(array);
	return (median);
}
