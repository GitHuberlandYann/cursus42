/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:19:58 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/27 14:45:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *str)
{
	int	index;
	int	res;
	int	save;

	if (!str)
		return (-1);
	index = 0;
	res = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = res;
		res = 10 * res + (str[index] - '0');
		if (res < save)
			return (-1);
		++index;
	}
	if (str[index])
		return (-1);
	return (res);
}

int	parse_input(t_table *table, int ac, char **av)
{
	table->seats = ft_atoi(av[1]);
	table->t_die = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->satiety = ft_atoi(av[5]);
	else
		table->satiety = -1;
	return (table->seats < 1 || table->t_die < 1 || table->t_eat < 1
		|| table->t_sleep < 1 || (ac == 6 && table->satiety < 1));
}
