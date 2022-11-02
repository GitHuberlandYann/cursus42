/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:33 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:18:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_stack(t_stack *stack)
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

static int	ft_max_stack(t_stack *stack)
{
	int	index;
	int	res;

	res = stack->arr[0];
	index = 1;
	while (index < stack->size)
	{
		if (stack->arr[index] > res)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

static int	ft_smallest_of_bigs(int value, t_stack *stack)
{
	int	res;
	int	index;

	res = value + 1000; //if list > 1000 element, could have problem
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] < res && stack->arr[index] > value)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

static int  ft_cost_top(t_stack *stack, int value)
{
    int	index;
	int	res;

	res = -1;
	index = 0;
	while (index < stack->size && res == -1)
	{
		if (stack->arr[index] == value)
			res = index;
		++index;
	}
	if (res > stack->size / 2)
		res -= stack->size;
	return (res);
}

int	ft_get_place_insert(t_stack *stack, int value)
{
	int	max;
	int	min;
	int	sofb;
    int	res;

	max = ft_max_stack(stack);
	min = ft_min_stack(stack);
	if (value > max)
		res = ft_cost_top(stack, min);
	else if (value < min)
		res = ft_cost_top(stack, min);
	else
	{
		sofb = ft_smallest_of_bigs(value, stack);
		res = ft_cost_top(stack, sofb);
    }
    return (res);
}
