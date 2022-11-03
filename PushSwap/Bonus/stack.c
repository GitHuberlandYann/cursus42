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

#include "checker.h"

static void	ft_rotate(t_stack *stack)
{
	int	index;
	int	save;

	index = 0;
	save = stack->arr[index];
	while (index < stack->size - 1)
	{
		stack->arr[index] = stack->arr[index + 1];
		++index;
	}
	stack->arr[index] = save;
}

static void	ft_rrotate(t_stack *stack)
{
	int	index;
	int	save;

	index = stack->size - 1;
	save = stack->arr[index];
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		--index;
	}
	stack->arr[index] = save;
}

static void	ft_pushstack(t_stack *dst, t_stack *src)
{
	int	index;

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

static void	ft_swap(int *tab)
{
	int	save;

	save = tab[1];
	tab[1] = tab[0];
	tab[0] = save;
}

void	ft_operation(t_stack *a, t_stack *b, int operation)
{
	if (operation == SA)
		ft_swap(a->arr);
	else if (operation == SB)
		ft_swap(b->arr);
	else if (operation == PA)
		ft_pushstack(a, b);
	else if (operation == PB)
		ft_pushstack(b, a);
	else if (operation == RA)
		ft_rotate(a);
	else if (operation == RB)
		ft_rotate(b);
	else if (operation == RRA)
		ft_rrotate(a);
	else if (operation == RRB)
		ft_rrotate(b);
}
