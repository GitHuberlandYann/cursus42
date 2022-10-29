/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:32:21 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 19:32:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* this function sorts stack a without using stack b */
/* obviously a BAD algo */

void	ft_sort_no_b(t_stack *a, t_stack *b)
{
	if (b->size == 0 && ft_stack_sorted(a))
		return ;
	if (a->arr[0] > a->arr[1] && a->arr[1] != 0)
		ft_operation(a, 0, SA);
	else
		ft_operation(a, 0, RA);
	//ft_display_stack(*a);
	ft_sort_no_b(a, b);
}
