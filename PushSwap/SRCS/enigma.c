/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enigma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:58:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/30 14:52:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->size - 1)
	{
		if (stack->arr[index] > stack->arr[index + 1])
			return (0);
		++index;
	}
	return (1);
}

void	ft_compute(t_stack *a, t_stack *b)
{
	if (b->size == 0 && ft_stack_sorted(a))
		return ;
	// ft_display_stack(*a);
	//ft_sort_section_selection(a, b, 22);
	//ft_sort_section_insertion(a, b, 19);
	//ft_sort_insertion_big(a, b, 20);
	//ft_sort_insertion(a, b);
	//ft_sort_bubble(a);
	//ft_sort_selection(a, b);
	//ft_sort_no_b(a);
	b->r = 0;
	b->rr = 0;
	a->r = 0;
	a->rr = 0;
	a->s_size = 20;
	ft_sort_big(a, b);
	// if (a->size <= 6)
	// 	ft_small(a, b);
	// else
	// 	ft_big(a, b);
	ft_display_stack(*a);
	ft_stack_sorted(a) ? ft_putstr("SORTED\n") : ft_putstr("NOT SORTED\n");
}
