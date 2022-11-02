/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_unwanted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:45 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:18:45 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_lis(int value, t_stack *lis)
{
	int	index;

	index = 0;
	while (index < lis->size)
	{
		if (value == lis->arr[index])
			return (1);
		++index;
	}
	return (0);
}

static int	ft_more_unwanted(t_stack *a, t_stack *lis, int end, int start)
{
	int	index;

	index = start;
	while (index < end)
	{
		if (!ft_check_lis(a->arr[index], lis))
			return (1);
		++index;
	}
	return (0);
}

void	ft_push_unwanted(t_stack *a, t_stack *b, t_stack *lis)
{ //could opti by pushing closest unwanted found
	int	count;
	int	size;

	count = 0;
	size = a->size;
	while (count < size && ft_more_unwanted(a, lis, size - count, 0))
	{
		if (ft_check_lis(a->arr[0], lis))
		{
			if (a->arr[1] < a->arr[0]
				&& (a->arr[1] > a->arr[a->size - 1] || count == 0))
			{
				ft_exec_swap(a, b, 0);
				if (ft_more_unwanted(a, lis, size - count - 1, 1))
					ft_operation(a, NULL, R);
				else
					return ;
			}
			else
				ft_operation(a, NULL, R);
		}
		else
			ft_exec_push(a, b, "pb\n");
		++count;
	}
}
