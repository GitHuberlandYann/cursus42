/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:22 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/31 13:35:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_free_return(int *tab)
{
	free(tab);
	return (0);
}

static int	ft_check_arg(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			if (str[index] != '-' || index > 0 || !str[index + 1])
				return (1);
		}
		++index;
	}
	return (0);
}

static int	ft_duplicate(int *tab, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (tab[index] == value)
			return (1);
		++index;
	}
	return (0);
}

static int	*ft_check_args(int ac, char **av)
{
	int		index;
	int		*res;
	long	buf;

	res = malloc(sizeof(*res) * (ac - 1));
	if (!res)
		return (0);
	index = 1;
	while (index < ac)
	{
		if (ft_check_arg(av[index]))
			return (ft_free_return(res));
		buf = ft_atoi(av[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index - 1))
			return (ft_free_return(res));
		res[index - 1] = buf;
		++index;
	}
	return (res);
}

static int	ft_situate(int *tab, int value, int size)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (index < size)
	{
		if (tab[index] < value)
			++res;
		++index;
	}
	return (res);
}

static int	*ft_transform_tab(int *tab, int size)
{
	int	index;
	int	*res;

	res = malloc(sizeof(*res) * size);
	if (!res)
	{
		free(tab);
		return (0);
	}
	index = 0;
	while (index < size)
	{
		res[index] = ft_situate(tab, tab[index], size);
		++index;
	}
	free(tab);
	return (res);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*tab;

	if (ac > 1)
	{
		tab = ft_check_args(ac, av);
		if (tab)
		{
			a.arr = ft_transform_tab(tab, ac - 1);
			if (!a.arr)
				return (1);
			b.arr = malloc(sizeof(*(b.arr)) * (ac - 1));
			if (b.arr)
			{
				a.size = ac - 1;
				b.size = 0;
				ft_compute(&a, &b);
				free(b.arr);
			}
			free(a.arr);
		}
		else
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
	return (0);
}
