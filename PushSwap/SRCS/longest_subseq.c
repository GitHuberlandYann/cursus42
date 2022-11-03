/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subseq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:37 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:18:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_free_return(t_stack *res, int *tab)
{
	free(res);
	free(tab);
	return (NULL);
}

static void	ft_lis(int *a, int *d, int *p, int size)
{
	int	index;
	int	sub_index;

	index = 1;
	while (index < size)
	{
		sub_index = 0;
		while (sub_index < index)
		{
			if (a[sub_index] < a[index] && d[index] < d[sub_index] + 1)
			{
				d[index] = d[sub_index] + 1;
				p[index] = sub_index;
			}
			++sub_index;
		}
		++index;
	}
}

static int	ft_get_max_lis(int *d, int *ans, int size)
{
	int	index;
	int	res;

	*ans = d[0];
	res = 0;
	index = 0;
	while (index < size)
	{
		if (d[index] > *ans)
		{
			*ans = d[index];
			res = index;
		}
		++index;
	}
	return (res);
}

static void	ft_set_subseq(int *p, int pos, t_stack *res, int *a)
{
	int	index;

	res->arr = malloc(sizeof(*res->arr) * res->size);
	if (!res->arr)
		return ;
	index = res->size - 1;
	while (pos != -1)
	{
		res->arr[index] = a[pos];
		pos = p[pos];
		--index;
	}
}

/* may want to find lis for each possible rotation of stack */
/* d[index] = longest lis untill index */
/* p[index] = index j at witch highest value d[index] was obtained */
t_stack	*ft_longest_subseq(t_stack *stack)
{
	int		*d;
	int		*p;
	int		pos;
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	d = malloc(sizeof(*d) * stack->size);
	if (!d)
		return (ft_free_return(res, NULL));
	p = malloc(sizeof(*p) * stack->size);
	if (!p)
		return (ft_free_return(res, d));
	ft_arrayset(d, 1, stack->size);
	ft_arrayset(p, -1, stack->size);
	ft_lis(stack->arr, d, p, stack->size);
	pos = ft_get_max_lis(d, &res->size, stack->size);
	ft_set_subseq(p, pos, res, stack->arr);
	free(d);
	free(p);
	return (res);
}
