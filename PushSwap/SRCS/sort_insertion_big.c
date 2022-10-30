/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:26:06 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 11:26:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//FAILURE, THIS IS NOT THE WAY

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	ft_max_stack(t_stack *stack)
{
	int	index;
	int	res;

	res = stack->arr[0];
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] > res)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

static void	ft_rotate_max(t_stack *stack, int max)
{
	int	start;
	int	end;

	start = 0;
	end = stack->size - 1;
	while (stack->arr[start] >= max)
		++start;
	while (stack->arr[end] >= max)
		--end;
	end = stack->size - 1 - end;
	if (start < end)
		ft_operation(0, stack, RB);
	else
		ft_operation(0, stack, RRB);
}

static int	ft_small_of_bigs(int value, t_stack *stack)
{
	int	res;
	int	index;

	res = value + 100;
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] < res && stack->arr[index] > value)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

static void	ft_rotate(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->arr[index] != value)
		++index;
	if (index <= stack->size / 2)
		ft_operation(stack, 0, RA);
	else
		ft_operation(stack, 0, RRA);
}

static void	ft_insert(t_stack *stack, int value)
{
	int	max;
	int	sofb;

	max = ft_max_stack(stack);
	if (value > max)
	{
		while (stack->arr[0] != 0)
			ft_rotate(stack, 0);
	}
	else
	{
		sofb = ft_small_of_bigs(value, stack);
		
		while (stack->arr[0] != sofb)
			ft_rotate(stack, sofb);
	}
}

void	ft_sort_insertion_big(t_stack *a, t_stack *b, int section)
{
	int	min;
	int	max;
	int	count;

	min = 0;
	max = a->size - 1;
	while (min < a->size)
	{
		if (a->arr[0] == min)
		{
			ft_operation(a, 0, RA);
			++min;
		}
		else
		{
			ft_operation(a, b, PB);
			if (b->arr[0] > max / 2 && b->size > 3)
				ft_operation(0, b, RB);
		}
	}
	while (b->size)
	{
		max = min + ft_min(section, b->size);
		count = 0;
		while (count < max - min)
		{
				// ft_printf("%d : b_size %d, min %d, max %d, section %d\n", count, b->size, min, max, section);
				// ft_display_stack(*a);
			while (b->arr[0] > max)
			{
				ft_rotate_max(b, max);
			}
			ft_insert(a, b->arr[0]);
			ft_operation(a, b, PA);
			++count;
		}
		min += max;
	}
	while (a->arr[0] != 0)
		ft_rotate(a, 0);
}
