/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:53:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/03 13:39:07 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_exec_push(a, b, "pb\n");
	if (ft_kinda_sorted(a))
		ft_exec_swap(a, b, 0);
	while (b->arr[0] != a->size && a->arr[0] != b->arr[0] + 1)
		ft_put_ontop(a, b->arr[0] + 1);
	while (b->arr[0] == a->size && a->arr[0] != 0)
		ft_put_ontop(a, 0);
	ft_exec_push(a, b, "pa\n");
	while (a->arr[0] != 0)
		ft_put_ontop(a, 0);
}

static void	ft_five_stack(t_stack *a, t_stack *b)
{
	ft_exec_push(a, b, "pb\n");
	ft_exec_push(a, b, "pb\n");
	if (ft_kinda_sorted(a))
		ft_exec_swap(a, b, 0);
	ft_insert_back(a, b);
	ft_put_ontop(a, 0);
}

static void	ft_six_stack(t_stack *a, t_stack *b)
{
	ft_exec_push(a, b, "pb\n");
	ft_exec_push(a, b, "pb\n");
	ft_exec_push(a, b, "pb\n");
	if (ft_kinda_sorted(a))
		ft_exec_swap(a, b, 0);
	ft_insert_back(a, b);
	ft_put_ontop(a, 0);
}

void	ft_sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		ft_three_stack(a, b);
	else if (a->size == 4)
		ft_four_stack(a, b);
	else if (a->size == 5)
		ft_five_stack(a, b);
	else if (a->size == 6)
		ft_six_stack(a, b);
}
