/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:22 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/30 14:51:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *ft_free_return(int *tab)
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
			if (str[index] != '-' || (str[index] == '-' && (!str[index + 1] || index > 0)))
				return (0);
		}
		++index;
	}
	return (1);
}

static int	*ft_check_args(int ac, char **av)
{
	int	index;
	int	*res;

	res = malloc(sizeof(*res) * (ac - 1));
	if (!res)
		return (0);
	index = 1;
	while (index < ac)
	{
		if (!ft_check_arg(av[index]))
			return (ft_free_return(res));
		res[index - 1] = ft_atoi(av[index]);
		++index;
	}
	return (res);
}

static int	ft_check_duplicate(int *tab, int limit)
{
	int	index;
	int	subindex;

	index = 0;
	while (index < limit)
	{
		subindex = 0;
		while (subindex < index)
		{
			if (tab[subindex] == tab[index])
				return (0);
			++subindex;
		}
		++index;
	}
	return (1);
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
	int	*tab;

	if (ac > 1)
	{
		tab = ft_check_args(ac, av);
		if (tab)
		{
			if (!ft_check_duplicate(tab, ac - 1))
			{
				ft_putstr("Error\n");
				free(tab);
				return (1);
			}
			//ft_putstr("enough arguments.\n");
			a.arr = ft_transform_tab(tab, ac - 1);
			if (!a.arr)
				return (1);
			b.arr = malloc(sizeof(*(b.arr)) * (ac - 1));
			if (b.arr)
			{
				a.size = ac - 1;
				b.size = 0;
				// ft_display_stack(a);
				// ft_display_stack(b);
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