/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:53:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:27:56 by yhuberla         ###   ########.fr       */
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

static void	ft_three_stack(t_stack *a, t_stack *b)
{
	if (a->arr[0] > a->arr[1])
	{
		if (a->arr[2] > a->arr[0])
			ft_exec_swap(a, b, 0);
		else
		{
			ft_operation(a, 0, R);
			if (a->arr[0] > a->arr[1])
				ft_exec_swap(a, b, 0);
		}
	}
	else
	{
		ft_operation(a, 0, RR);
		if (a->arr[0] > a->arr[1])
			ft_exec_swap(a, b, 0);
	}
}

static void	ft_four_stack(t_stack *a, t_stack *b)
{
	if (ft_kinda_foursorted(a))
	{
		while (a->arr[0] != 0)
			ft_put_ontop(a, 0);
	}
	else
	{
		ft_exec_push(a, b, "pb\n");
		if (!ft_kinda_threesorted(a))
			ft_exec_swap(a, b, 0);
		while (b->arr[0] != a->size && a->arr[0] != b->arr[0] + 1)
			ft_put_ontop(a, b->arr[0] + 1);
		while (b->arr[0] == a->size && a->arr[0] != 0)
			ft_put_ontop(a, 0);
		ft_exec_push(a, b, "pa\n");
		while (a->arr[0] != 0)
			ft_put_ontop(a, 0);
	}
}

void	ft_sort_small(t_stack *a, t_stack *b) //a->size + b->size <= 6
{
	if (ft_stack_sorted(a))
		return ;
	if (a->size == 2)
		ft_exec_swap(a, b, 0);
	else if (a->size == 3)
		ft_three_stack(a, b);
	else if (a->size == 4)
		ft_four_stack(a, b);
	else if (a->size == 5)
		ft_putstr("todo\n");
	else if (a->size == 6)
		ft_putstr("todo\n");
	ft_exec_push(a, b, ""); //print rotations and swaps left
}
