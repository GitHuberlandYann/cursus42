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

static int	ft_get_loc(t_stack *b, int goal)
{
	int	res;

	res = 0;
	while (b->arr[res] != goal)
		++res;
	return (res);
}

static void	ft_rotate(t_stack *b, int goal)
{
	int	location;

	location = ft_get_loc(b, goal);
	if (location <= b->size / 2)
		ft_operation(0, b, RB);
	else
		ft_operation(0, b, RRB);
}

static int	ft_get_min(t_stack *stack)
{
	int	index;
	int	res;

	res = stack->arr[0];
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] < res)
			res = stack->arr[index];
		++index;
	}
	return (res);
}

static int	ft_get_max(t_stack *stack)
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

static void	ft_insert(int value, t_stack *stack)
{
	int	max;
	int	min;

	max = ft_get_max(stack);
	min = ft_get_min(stack);
	if (value > max)
	{
		while (stack->arr[0] != max)
			ft_rotate(stack, max);
	}
	else if (value < min)
	{
		while (stack->arr[0] != max)
			ft_rotate(stack, min);
	}
	else
	{
		while (!(value > stack->arr[0] && value < stack->arr[stack->size - 1]))
			ft_operation(0, stack, RB);
	}
}

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
		{
			ft_operation(a, b, PB);
			if (b->size == 2 && b->arr[0] < b->arr[1])
				ft_operation(0, b, SB);
		}
		else
		{
			ft_insert(a->arr[0], b);
			ft_operation(a, b, PB);
		}
		// ft_display_stack(*a);
		// ft_display_stack(*b);
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