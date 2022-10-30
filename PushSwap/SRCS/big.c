/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:56:16 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 14:56:16 by marvin           ###   ########.fr       */
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

static void	ft_ope_no_rot(t_stack *a, t_stack *b, int ope)
{
	while (a->r || a->rr || b->r || b->rr)
	{
		if (a->r && b->r)
		{
			ft_putstr("rr\n");
			--a->r;
			--b->r;
		}
		else if (a->rr && b->rr)
		{
			ft_putstr("rrr\n");
			--a->rr;
			--b->rr;
		}
		else if (a->r)
		{
			ft_putstr("ra\n");
			--a->r;
		}
		else if (b->r)
		{
			ft_putstr("rb\n");
			--b->r;
		}
		else if (a->rr)
		{
			ft_putstr("rra\n");
			--a->rr;
		}
		else if (b->rr)
		{
			ft_putstr("rrb\n");
			--b->rr;
		}
	}
	ft_operation(a, b, ope);
}

static void  ft_rotate_range(t_stack *stack, int min, int max, int diff)
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
	if (start < end + diff)
	{
		++stack->r;
		ft_rot_big(stack, RA);
	}
	else
	{
		++stack->rr;
		ft_rot_big(stack, RRA);
	}
}

static void	ft_rotate(t_stack *stack, int goal, int diff)
{
	int	index;

	index = 0;
	while (stack->arr[index] != goal)
		++index;
	if (index <= (stack->size + diff) / 2)
	{
		++stack->r;
		ft_rot_big(stack, RA);
	}
	else
	{
		++stack->rr;
		ft_rot_big(stack, RRA);
	}
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

static int	ft_small_of_bigs(int value, t_stack *stack, int section)
{
	int	res;
	int	index;

	res = value + section;
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

static void	ft_insert_inb(int value, t_stack *stack, int section, int diff)
{
	int	max;
	int	min;
	int	bofs;
	int	sofb;

	max = ft_max_stack(stack);
	min = ft_min_stack(stack);
	if (value > max)
	{
		while (stack->arr[0] != max)
			ft_rotate(stack, max, diff);
	}
	else if (value < min)
	{
		while (stack->arr[0] != max)
			ft_rotate(stack, max, diff);
	}
	else
	{
		bofs = ft_big_of_smalls(value, stack);
		sofb = ft_small_of_bigs(value, stack, section);
		//ft_printf("bigofs %d, smallofb %d\n", bofs, sofb);
		while (stack->arr[0] != bofs && stack->arr[stack->size - 1] != sofb)
			ft_rotate_range(stack, bofs, sofb, diff);
	}
}

static void ft_push_sectionab(t_stack *a, t_stack *b, int min, int max)
{
    int count;

    count = 0;
    while (count < max - min)
    {
        while (a->arr[0] < min || a->arr[0] >= max)
            ft_rotate_range(a, min, max, b->r - b->rr); //memorize those and do them in ft_insert whit rr and rrr
        if (b->size < 2)
			ft_ope_no_rot(a, b, PB); //ft_operation(a, b, PB);
		else
		{
			ft_insert_inb(a->arr[0], b, a->s_size, a->r - a->rr);
			ft_ope_no_rot(a, b, PB); //ft_operation(a, b, PB);
			// ft_display_stack(*a);
			// ft_display_stack(*b);
		}
        ++count;
    }
}

static void ft_push_ba(t_stack *a, t_stack *b, int move)
{
	if (move)
	{
		while (a->arr[0] != b->arr[0] + 1)
			ft_rotate_range(a, b->arr[0], b->arr[0] + 2, b->r - b->rr);
	}
	while (b->size)
		ft_ope_no_rot(a, b, PA); //ft_operation(a, b, PA);
}

void	ft_sort_big(t_stack *a, t_stack *b) //insertion has been chosen for now
{
	int	section;
	int	min;
	int	max;

		// ft_display_stack(*a);
		// ft_display_stack(*b);
	section = a->size / a->s_size + (a->size % a->s_size > 0);
	a->nb_s = section;
	while (section > 0)
	{
		min = a->s_size * (section - 1) - (a->s_size - a->size % a->s_size) * (a->size % a->s_size > 0);
		max = a->s_size * section - (a->s_size - a->size % a->s_size) * (a->size % a->s_size > 0);
		if (section == 1 && (a->size % a->s_size > 0))
		{
			min = 0;
			max = a->size % a->s_size;
		}
		ft_push_sectionab(a, b, min, max);
        while (b->arr[0] != max - 1)
            ft_rotate(b, max - 1, a->r - a->rr); //memorize this and do it in push_ba to use rr and rrr
		// ft_display_stack(*a);
		// ft_display_stack(*b);
        ft_push_ba(a, b, section != a->nb_s);
        --section;
	}
}
