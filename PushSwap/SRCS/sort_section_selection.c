/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_section_selection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:10:08 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 23:10:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
            ft_rotate(a, min, max);
        ft_operation(a, b, PB);
        ++count;
    }
}

static int  ft_stack_reverse_sorted(t_stack *stack)
{
    int index;

    index = 0;
    while (index < stack->size - 1)
    {
        if (stack->arr[index] < stack->arr[index + 1])
            return (0);
        ++index;
    }
    return (1);
}

static void	ft_rotate_b(t_stack *stack, int goal)
{
	int	location;

	location = 0;
	while (stack->arr[location] != goal)
		++location;
	if (location <= stack->size / 2)
		ft_operation(0, stack, RB);
	else
		ft_operation(0, stack, RRB);
}

static void	ft_sort_section_b(t_stack *a, t_stack *b, int min, int move)
{
	int	limit;
	int	save;

	limit = min + b->size - 1;
	save = limit;
	while (min <= limit && !ft_stack_reverse_sorted(b))
	{
		while (b->arr[0] != limit)
			ft_rotate_b(b, limit);
    	if (!ft_stack_reverse_sorted(b))
		{
			ft_operation(a, b, PA);
			--limit;
		}
	}
	if (!move)
		return ;
	while (limit < save)
	{
		ft_operation(a, b, PB);
		++limit;
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

void    ft_sort_section_selection(t_stack *a, t_stack *b)
{
    int section;
	int	save;
	int	min;
	int	max;

    section = a->size / 10 + (a->size % 10 > 0);
    save = section;
	while (section > 0)
    {
		min = 10 * (section - 1) - (10 - a->size % 10) * (a->size % 10 > 0);
		max = 10 * section - (10 - a->size % 10) * (a->size % 10 > 0);
		if (section == 1 && (a->size % 10 > 0))
		{
			min = 0;
			max = a->size % 10;
		}
        ft_push_tenab(a, b, min, max);
		// ft_display_stack(*a);
		// ft_display_stack(*b);
		ft_sort_section_b(a, b, min, section != save);
		// ft_display_stack(*a);
		// ft_display_stack(*b);
        ft_push_ba(a, b, section != save);
        --section;
    }
}
