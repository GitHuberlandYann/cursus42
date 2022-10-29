/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:24:34 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 20:24:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bubble(t_stack *a)
{
	int	count;

	while (!ft_stack_sorted(a))
	{
		count = 0;
		while (count < a->size)
		{
			if (a->arr[0] > a->arr[1] && !(a->arr[0] == a->size - 1 && a->arr[1] == 0))
				ft_operation(a, 0, SA);
			if (!ft_stack_sorted(a))
				ft_operation(a, 0, RA);
			//ft_display_stack(*a);
			++count;
		}
	}
}