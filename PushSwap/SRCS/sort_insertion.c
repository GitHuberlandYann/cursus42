/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:46:38 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 20:46:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_insertion(t_stack *a, t_stack *b)
{
	int	count;
	int	limit;

	count = 0;
	limit = a->size - 1;
	while (count < limit && !ft_stack_sorted(a))
	{
		if (a->arr[0] > a->arr[1])
			ft_operation(a, 0, SA);
		if (b->size < 2)
			ft_operation(a, b, PB);
		else
		{
			while (!(a->arr[0] > b->arr[0] && a->arr[0] > b->arr[b->size - 1])
				&& !(a->arr[0] < b->arr[0] && a->arr[0] < b->arr[b->size - 1])
				&& !(a->arr[0] > b->arr[0] && a->arr[0] < b->arr[b->size - 1]))
				ft_operation(0, b, RB);
			ft_operation(a, b, PB);
		}
		++count;
	}
	if (count > 1)
	{
		while (b->arr[0] < b->arr[b->size - 1])
			ft_operation(0, b, RB);
	}
	while (count > 0)
	{
		ft_operation(a, b, PA);
		--count;
	}
}