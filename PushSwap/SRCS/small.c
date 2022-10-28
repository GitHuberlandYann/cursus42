/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 14:30:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_three_stack(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
	{
		if (stack->arr[2] > stack->arr[0])
			ft_operation(stack, 0, SA);
		else
		{
			ft_operation(stack, 0, RA);
			if (stack->arr[0] > stack->arr[1])
				ft_operation(stack, 0, SA);
		}
	}
	else
	{
		ft_operation(stack, 0, RRA);
		if (stack->arr[0] > stack->arr[1])
			ft_operation(stack, 0, SA);
	}
}

void	ft_small(t_stack *a, t_stack *b) //a->size + b->size <= 6
{
	if (b->size == 0 && ft_stack_sorted(a))
		return ;
	if (b->size == 0)
	{
    	if (a->size == 2)
			ft_operation(a, 0, SA);
		else if (a->size == 3)
			ft_three_stack(a);
	}
	else if (ft_stack_sorted(a))
	{
		ft_putstr("todo in ft_small");
	}

}