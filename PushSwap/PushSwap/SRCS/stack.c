/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:43:47 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 13:43:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack, char *txt)
{
	int	index;
	int	save;

	if (txt)
		ft_putstr(txt);
	index = 0;
	save = stack->arr[index];
	while (index < stack->size - 1)
	{
		stack->arr[index] = stack->arr[index + 1];
		++index;
	}
	stack->arr[index] = save;
	
}

void	ft_rrotate(t_stack *stack, char *txt)
{
	int	index;
	int	save;

	if (txt)
		ft_putstr(txt);
	index = stack->size - 1;
	save = stack->arr[index];
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		--index;
	}
	stack->arr[index] = save;
}

void	ft_pushstack(t_stack *dst, t_stack *src, char *txt)
{
	int	index;

	if (txt)
		ft_putstr(txt);
	index = dst->size;
	while (index > 0)
	{
		dst->arr[index] = dst->arr[index - 1];
		--index;
	}
	dst->arr[0] = src->arr[0];
	while (index < src->size - 1)
	{
		src->arr[index] = src->arr[index + 1];
		++index;
	}
	++(dst->size);
	--(src->size);
}

void	ft_swap(int *tab, char *txt)
{
	int	save;

	if (txt)
		ft_putstr(txt);
	save = tab[1];
	tab[1] = tab[0];
	tab[0] = save;
}

void	ft_operation(t_stack *a, t_stack *b, int operation)
{
	if (operation == SA)
		ft_swap(a->arr, "sa\n");
	else if (operation == SB)
		ft_swap(b->arr, "sb\n");
	else if (operation == SS)
	{
		ft_swap(a->arr, "ss\n");
		ft_swap(b->arr, 0);
	}
	else if (operation == PA)
		ft_pushstack(a, b, "pa\n");
	else if (operation == PB)
		ft_pushstack(b, a, "pb\n");
	else if (operation == RA)
		ft_rotate(a, "ra\n");
	else if (operation == RB)
		ft_rotate(b, "rb\n");
	else if (operation == RR)
	{
		ft_rotate(a, "rr\n");
		ft_rotate(b, 0);
	}
	else if (operation == RRA)
		ft_rrotate(a, "rra\n");
	else if (operation == RRB)
		ft_rrotate(b, "rrb\n");
	else if (operation == RRR)
	{
		ft_rrotate(a, "rrr\n");
		ft_rrotate(b, 0);
	}
}
