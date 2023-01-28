/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:16:48 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/28 14:23:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*sleepeat(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (!(philo->num & 1))
		usleep((philo->table->t_eat * 1000) / 2);
	while (philo->table->alive)
	{
		pthread_mutex_lock(philo->left_fork);
		output_msg(philo, MSG_FORK);
		if (philo->table->seats == 1)
		{
			usleep(philo->table->t_die * 2000);
			return (NULL);
		}
		pthread_mutex_lock(philo->right_fork);
		output_msg(philo, MSG_FORK);
		output_msg(philo, MSG_EAT);
		philo->t_last_meal = get_time();
		usleep(philo->table->t_eat * 1000);
		++philo->meal_count;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		output_msg(philo, MSG_SLEEP);
		usleep(philo->table->t_sleep * 1000);
		output_msg(philo, MSG_THINK);
	}
	return (NULL);
}

static void	setup_philo(t_table *table, t_philo *philo, int number)
{
	philo->num = number;
	philo->t_last_meal = table->t_start;
	philo->meal_count = 0;
	philo->left_fork = &table->forks[number - 1];
	if (number == table->seats)
		philo->right_fork = &table->forks[0];
	else
		philo->right_fork = &table->forks[number];
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
	table->t_start = get_time();
	while (index < table->seats)
	{
		setup_philo(table, &table->philos[index], index + 1);
		if (pthread_create(&table->philos[index].thread, NULL, &sleepeat,
				&table->philos[index]))
		{
			destroy_all_mutex(table, table->seats);
			destroy_all_threads(table, index);
			return (output_error("thread create failed\n"));
		}
		++index;
	}
	return (0);
}
