/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_section_insertion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:57:14 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 01:57:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_b(t_stack *b, int goal)
{
	int	location;

	location = 0;
	while (b->arr[location] != goal)
		++location;
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

static int	ft_big_of_smalls(int value, t_stack *stack)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] > res && stack->arr[index] < value)
			res = stack->arr[index];
		++index;
	}
	if (res == -1)
		return (value);
	return (res);
}

static int	ft_small_of_bigs(int value, t_stack *stack)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	while (index < stack->size)
	{
		if (stack->arr[index] < res && stack->arr[index] > value)
			res = stack->arr[index];
		++index;
	}
	if (res == -1)
		return (value);
	return (res);
}

static void  ft_rotate_special_b(t_stack *stack, int min, int max)
{
    int start;
    int end;
    
    start = 0;
    end = stack->size - 1;
    while (stack->arr[start] < min || stack->arr[start] >= max)
        ++start;
    while (stack->arr[end] < min || stack->arr[end] >= max)
        --end;
    end = stack->size - 1 - end;
    if (start < end)
        ft_operation(0, stack, RB);
    else
        ft_operation(0, stack, RRB);
}

static void	ft_insert(int value, t_stack *stack)
{
	int	max;
	int	min;
	int	bofs;
	int	sofb;

	max = ft_get_max(stack);
	min = ft_get_min(stack);
	if (value > max)
	{
		while (stack->arr[0] != max)
			ft_rotate_b(stack, min);
	}
	else if (value < min)
	{
		while (stack->arr[0] != max)
			ft_rotate_b(stack, max);
	}
	else
	{
		bofs = ft_big_of_smalls(value, stack);
		sofb = ft_small_of_bigs(value, stack);
		while (stack->arr[0] != bofs && stack->arr[0] != sofb)
			ft_rotate_special_b(stack, bofs, sofb);
	}
}

static void  ft_rotate(t_stack *stack, int min, int max)
{
    int start;
    int end;
    
    start = 0;
    end = stack->size - 1;
    while (stack->arr[start] < min || stack->arr[start] >= max)
        ++start;
    while (stack->arr[end] < min || stack->arr[end] >= max)
        --end;
    end = stack->size - 1 - end;
    if (start < end)
        ft_operation(stack, 0, RA);
    else
        ft_operation(stack, 0, RRA);
}

static void ft_push_tenab(t_stack *a, t_stack *b, int min, int max)
{
    int count;

    count = 0;
    while (count < max - min)
    {
        while (a->arr[0] < min || a->arr[0] >= max)
            ft_rotate(a, min, max); //memorize those and do them in ft_insert whit rr and rrr
        if (b->size < 2)
			ft_operation(a, b, PB);
		else
		{
			ft_insert(a->arr[0], b);
			ft_operation(a, b, PB);
		}
        ++count;
    }
}

static void ft_push_ba(t_stack *a, t_stack *b, int move)
{
	if (move)
	{
		while (a->arr[0] != b->arr[0] + 1)
			ft_rotate(a, b->arr[0], b->arr[0] + 2);
	}
    while (b->size)
        ft_operation(a, b, PA);
}

void    ft_sort_section_insertion(t_stack *a, t_stack *b, int base)
{
    int section;
	int	save;
	int	min;
	int	max;

    section = a->size / base + (a->size % base > 0);
    save = section;
	while (section > 0)
    {
		min = base * (section - 1) - (base - a->size % base) * (a->size % base > 0);
		max = base * section - (base - a->size % base) * (a->size % base > 0);
		if (section == 1 && (a->size % base > 0))
		{
			min = 0;
			max = a->size % base;
		}
        ft_push_tenab(a, b, min, max);
        while (b->arr[0] != max - 1)
            ft_rotate_b(b, max - 1); //memorize this and do it in push_ba to use rr and rrr
		// ft_display_stack(*a);
		// ft_display_stack(*b);
        ft_push_ba(a, b, section != save);
        --section;
    }
}