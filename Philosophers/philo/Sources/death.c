/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:17:00 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 16:20:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	d_eat_h_check(t_philo *philo)
{
	int	t_last_meal;
	int	res;

	pthread_mutex_lock(&philo->table->var_access);
	t_last_meal = philo->t_last_meal;
	pthread_mutex_unlock(&philo->table->var_access);
	if (get_time() - t_last_meal >= philo->table->t_die)
	{
		output_msg(philo, MSG_DIE);
		pthread_mutex_lock(&philo->table->var_access);
		philo->table->alive = 0;
		pthread_mutex_unlock(&philo->table->var_access);
	}
	if (philo->table->satiety == -1)
		return (0);
	pthread_mutex_lock(&philo->table->var_access);
	res = philo->meal_count >= philo->table->satiety;
	pthread_mutex_unlock(&philo->table->var_access);
	return (res);
}

void	death_cycle(void *arg)
{
	int		index;
	int		satiety_count;
	int		loop;
	t_table	*table;

	table = arg;
	pthread_mutex_lock(&table->var_access);
	loop = table->alive;
	pthread_mutex_unlock(&table->var_access);
	while (loop)
	{
		index = -1;
		satiety_count = 0;
		while (table->alive && ++index < table->seats)
			satiety_count += d_eat_h_check(&table->philos[index]);
		if (satiety_count == table->seats)
		{
			pthread_mutex_lock(&table->var_access);
			table->alive = 0;
			pthread_mutex_unlock(&table->var_access);
		}
		pthread_mutex_lock(&table->var_access);
		loop = table->alive;
		pthread_mutex_unlock(&table->var_access);
	}
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	int	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}
