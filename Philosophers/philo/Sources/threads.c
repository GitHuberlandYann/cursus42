/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:16:48 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 10:41:49 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sleepeat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	output_msg(philo, MSG_FORK);
	if (philo->table->seats == 1)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	output_msg(philo, MSG_FORK);
	output_msg(philo, MSG_EAT);
	pthread_mutex_lock(&philo->table->var_access);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&philo->table->var_access);
	ft_usleep(philo->table->t_eat);
	pthread_mutex_lock(&philo->table->var_access);
	++philo->meal_count;
	pthread_mutex_unlock(&philo->table->var_access);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	output_msg(philo, MSG_SLEEP);
	ft_usleep(philo->table->t_sleep);
	output_msg(philo, MSG_THINK);
	return (0);
}

static void	*normal_day(void *arg)
{
	int		loop;
	t_philo	*philo;

	philo = arg;
	if (!(philo->num & 1))
		ft_usleep(philo->table->t_eat / 2);
	pthread_mutex_lock(&philo->table->var_access);
	loop = philo->table->alive;
	pthread_mutex_unlock(&philo->table->var_access);
	while (loop)
	{
		if (sleepeat(philo))
			return (NULL);
		pthread_mutex_lock(&philo->table->var_access);
		loop = philo->table->alive;
		pthread_mutex_unlock(&philo->table->var_access);
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
	table->t_start = get_time();
	index = 0;
	while (index < table->seats)
	{
		setup_philo(table, &table->philos[index], index + 1);
		if (pthread_create(&table->philos[index].thread, NULL, &normal_day,
				&table->philos[index]))
		{
			destroy_all_threads(table, index);
			destroy_all_mutex(table, table->seats);
			return (output_error("thread create failed\n"));
		}
		++index;
	}
	return (0);
}
