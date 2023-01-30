/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:09:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 10:09:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sleepeat(t_philo *philo)
{
	if (!(philo->num & 1))
		usleep((philo->table->t_eat * 1000) / 2);
	while (1)
	{
		sem_wait(philo->table->forks);
		output_msg(philo, MSG_FORK);
		if (philo->table->seats == 1)
			return ;
		sem_wait(philo->table->forks);
		output_msg(philo, MSG_FORK);
		output_msg(philo, MSG_EAT);
		sem_wait(philo->table->var_access);
		philo->t_last_meal = get_time();
		sem_post(philo->table->var_access);
		usleep(philo->table->t_eat * 1000);
		sem_post(philo->table->forks);
		sem_post(philo->table->forks);
		++philo->meal_count;
		if (philo->meal_count == philo->table->satiety)
			sem_post(philo->table->full_belly);
		output_msg(philo, MSG_SLEEP);
		usleep(philo->table->t_sleep * 1000);
		output_msg(philo, MSG_THINK);
	}
	return ;
}

static void	launch_process(t_philo *philo)
{
	int	index;

	if (pthread_create(&philo->death, NULL, &death_check, philo))
	{
		index = -1;
		while (++index < philo->table->seats)
			sem_post(philo->table->full_belly);
		exit(output_error("thread create failed\n"));
	}
	sleepeat(philo);
	pthread_join(philo->death, NULL);
	exit(EXIT_SUCCESS);
}

static void	setup_philo(t_table *table, t_philo *philo, int number)
{
	philo->num = number;
	philo->t_last_meal = table->t_start;
	philo->meal_count = 0;
	philo->table = table;
}

int	init_processes(t_table *table)
{
	int	index;

	table->philos = malloc(sizeof(*table->philos) * table->seats);
	if (!table->philos)
	{
		close_semaphores(table, 0);
		return (output_error("malloc 'table->philos' failed\n"));
	}
	table->t_start = get_time();
	index = 0;
	while (index < table->seats)
	{
		setup_philo(table, &table->philos[index], index + 1);
		table->philos[index].pid = fork();
		if (table->philos[index].pid == -1)
		{
			kill_processes(table, index);
			close_semaphores(table, 0);
			return (output_error("fork failed\n"));
		}
		if (!table->philos[index].pid)
			launch_process(&table->philos[index]);
		++index;
	}
	return (0);
}

void	kill_processes(t_table *table, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
	{
		kill(table->philos[index].pid, SIGKILL);
		++index;
	}
	free(table->philos);
}
