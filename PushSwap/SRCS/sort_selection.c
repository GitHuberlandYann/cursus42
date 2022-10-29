/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:55:31 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 19:55:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_loc(t_stack *a, int goal)
{
	int	res;

	res = 0;
	while (a->arr[res] != goal)
		++res;
	return (res);
}

static void	ft_rotate(t_stack *a, int goal)
{
	int	location;

	location = ft_get_loc(a, goal);
	if (location <= a->size / 2)
		ft_operation(a, 0, RA);
	else
		ft_operation(a, 0, RRA);
}

void	ft_sort_selection(t_stack *a, t_stack *b)
{
	int	goal;
	int	limit;

	limit = a->size - 1;
	goal = 0;
	while (goal < limit && !ft_stack_sorted(a))
	{
		while (a->arr[0] != goal)
			ft_rotate(a, goal);
    	if (!ft_stack_sorted(a))
		{
			ft_operation(a, b, PB);
			++goal;
		}
	}
	while (goal > 0)
	{
		ft_operation(a, b, PA);
		--goal;
	}
	//ft_display_stack(*a);
}