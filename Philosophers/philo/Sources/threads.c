/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:16:48 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/27 16:00:06 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	diff_time(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_usec - start.tv_usec);
}

static void	*sleepeat(void *arg)
{
	t_philo	*philo;

	philo = arg;
	gettimeofday(&philo->t_last_meal, NULL);
	output_msg(philo, diff_time(philo->t_last_meal), MSG_DIE);
	return (NULL);
}

static void	setup_philo(t_table *table, t_philo *philo, int number)
{
		philo->num = number;
		philo->meal_count = 0;
		if (number == 1)
			philo->left_fork = table->forks[table->seats - 1];
		else
			philo->left_fork = table->forks[number - 1];
		if (number == table->seats)
			philo->right_fork = table->forks[0];
		else
			philo->right_fork = table->forks[number];
		philo->table = table;
}

void	destroy_all_threads(t_table *table, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
	{
		pthread_join(table->philos[index].thread, NULL);
		++index;
	}
	free(table->philos);
}

int	init_threads(t_table *table)
{
	int	index;

	table->alive = 1;
	table->philos = malloc(sizeof(*table->philos) * table->seats);
	if (!table->philos)
	{
		destroy_all_mutex(table, table->seats);
		return (output_error("malloc 'table->philos' failed\n"));
	}
	index = 0;
	while (index < table->seats)
	{
		setup_philo(table, &table->philos[index], index + 1);
		if (pthread_create(&table->philos[index].thread, NULL, &sleepeat, &table->philos[index]))
		{
			destroy_all_mutex(table, table->seats);
			destroy_all_threads(table, index);
			return (output_error("thread create failed\n"));
		}
		++index;
	}
	return (0);
}
