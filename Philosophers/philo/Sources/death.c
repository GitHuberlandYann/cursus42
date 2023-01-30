/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:17:00 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 10:08:18 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	d_eat_h_check(t_philo *philo)
{
	if (philo->t_last_meal
		&& get_time() - philo->t_last_meal >= philo->table->t_die)
	{
		output_msg(philo, MSG_DIE);
		philo->table->alive = 0;
	}
	if (philo->table->satiety == -1)
		return (0);
	return (philo->meal_count >= philo->table->satiety);
}

void	death_cycle(void *arg)
{
	int		index;
	int		satiety_count;
	t_table	*table;

	table = arg;
	while (table->alive)
	{
		index = 0;
		satiety_count = 0;
		while (table->alive && index < table->seats)
		{
			satiety_count += d_eat_h_check(&table->philos[index]);
			++index;
		}
		if (satiety_count == table->seats)
			table->alive = 0;
	}
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
