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

static int	ft_kinda_foursorted(t_stack *a)
{
	int	c;
	int	d;
	int	e;
	int	f;

	c = a->arr[0];
	d = a->arr[1];
	e = a->arr[2];
	f = a->arr[3];
	return ((c < d && d < e && e < f) || (d < e && e < f && f < c)
			|| (e < f && f < c && c < d) || (f < c && c < d && d < e));
}

static int	ft_kinda_threesorted(t_stack *a)
{
	// takes stack of 3 and say if sorted by rotation or not
	int	c;
	int	d;
	int	e;

	c = a->arr[0];
	d = a->arr[1];
	e = a->arr[2];
	return ((c < d && d < e) || (d < e && e < c) || (e < c && c < d));
}

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

static void	ft_rotate(t_stack *a, int goal)
{
	int	location;

	location = 0;
	while (a->arr[location] != goal)
		++location;
	if (location <= a->size / 2)
		ft_operation(a, 0, RA);
	else
		ft_operation(a, 0, RRA);
}

void	ft_sort_small(t_stack *a, t_stack *b) //a->size + b->size <= 6
{
	if (ft_stack_sorted(a))
		return ;
    if (a->size == 2)
		ft_operation(a, 0, SA);
	else if (a->size == 3)
		ft_three_stack(a);
	else if (a->size == 4)
	{
		if (ft_kinda_foursorted(a))
		{
			while (a->arr[0] != 0)
				ft_rotate(a, 0);
		}
		else
		{
			ft_operation(a, b, PB);
			if (!ft_kinda_threesorted(a))
				ft_operation(a, 0, SA);
			while (b->arr[0] != a->size && a->arr[0] != b->arr[0] + 1)
				ft_rotate(a, b->arr[0] + 1);
			while (b->arr[0] == a->size && a->arr[0] != 0)
				ft_rotate(a, 0);
			ft_operation(a, b, PA);
			while (a->arr[0] != 0)
				ft_rotate(a, 0);
		}
	}
	else if (a->size == 5)
		ft_putstr("todo\n");
	else if (a->size == 6)
		ft_putstr("todo\n");
}