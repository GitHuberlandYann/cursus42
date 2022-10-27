/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:22 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/27 17:51:02 by yhuberla         ###   ########.fr       */
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

static int	ft_duplicate(int *tab, int limit)
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

int	main(int ac, char **av)
{
	int	*taba;
	int	*tabb;
	int	sizea;
	int	sizeb;

	if (ac > 1)
	{
		taba = ft_check_args(ac, av);
		if (taba)
		{
			if (!ft_duplicate(taba, ac - 1))
			{
				ft_putstr("Error\n");
				free(taba);
				return (1);
			}
			ft_putstr("enough arguments.\n");
			tabb = malloc(sizeof(*tabb) * (ac - 1));
			if (tabb)
			{
				sizea = ac - 1;
				sizeb = 0;
				ft_compute(taba, tabb, &sizea, &sizeb);
				free(tabb);
			}
			free(taba);
		}
		else
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
	return (0);
}