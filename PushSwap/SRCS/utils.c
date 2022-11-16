/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:17:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:17:47 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stack(t_stack stack)
{
	int	index;

	ft_printf("stack of size %d : ", stack.size);
	index = 0;
	while (index < stack.size)
	{
		ft_printf("%d ", stack.arr[index ++]);
	}
	ft_printf(" - r %d, rr %d\n", stack.r, stack.rr);
}

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

void	ft_put_ontop(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->arr[index] != value)
		++index;
	while (stack->arr[0] != value)
	{
		if (index <= stack->size / 2)
			ft_operation(stack, NULL, R);
		else
			ft_operation(stack, NULL, RR);
	}
}

int	ft_min_stack(t_stack *stack)
{
	int	index;
	int	res;

	res = stack->arr[0];
	index = 1;
	while (index < stack->size)
	{
		if (stack->arr[index] < res)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

int	ft_kinda_sorted(t_stack *stack)
{
	int	save;
	int	res;
	int	min;

	save = stack->arr[0];
	min = ft_min_stack(stack);
	ft_put_ontop(stack, min);
	res = !ft_stack_sorted(stack);
	ft_put_ontop(stack, save);
	stack->r = 0;
	stack->rr = 0;
	return (res);
}
