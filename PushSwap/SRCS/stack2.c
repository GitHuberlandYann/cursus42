/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:18 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:18:18 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_rotations(t_stack *a, t_stack *b)
{
	while (a->r && b->r)
	{
		ft_putstr("rr\n");
		--a->r;
		--b->r;
	}
	while (a->r)
	{
		ft_putstr("ra\n");
		--a->r;
	}
	while (b->r)
	{
		ft_putstr("rb\n");
		--b->r;
	}
}

static void	ft_do_rrotations(t_stack *a, t_stack *b)
{
	while (a->rr && b->rr)
	{
		ft_putstr("rrr\n");
		--a->rr;
		--b->rr;
	}
	while (a->rr)
	{
		ft_putstr("rra\n");
		--a->rr;
	}
	while (b->rr)
	{
		ft_putstr("rrb\n");
		--b->rr;
	}
}

void	ft_exec_swap(t_stack *a, t_stack *b, int stack)
{
	ft_do_rotations(a, b);
	ft_do_rrotations(a, b);
	if (stack == 0)
	{
		ft_operation(a, NULL, S);
		ft_putstr("sa\n");
	}
	else
	{
		ft_operation(b, NULL, S);
		ft_putstr("sb\n");
	}
}

void	ft_exec_push(t_stack *a, t_stack *b, char *msg)
{
	ft_do_rotations(a, b);
	ft_do_rrotations(a, b);
	if (msg[0] == '\0')
		return ;
	if (msg[1] == 'a')
		ft_operation(a, b, P);
	else if (msg[1] == 'b')
		ft_operation(b, a, P);
	ft_putstr(msg);
}
