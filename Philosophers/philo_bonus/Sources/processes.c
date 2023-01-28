//add header here

#include "philo_bonus.h"

static void	*sleepeat(t_philo *philo)
{
	philo->t_start = get_time();
	philo->t_last_meal = philo->t_start;
	if (!(philo->num & 1))
		usleep((philo->table->t_eat * 1000) / 2);
	while (1)
	{
		sem_wait(philo->table->forks);
		output_msg(philo, MSG_FORK);
		if (philo->table->seats == 1)
			return (NULL);
		sem_wait(philo->table->forks);
		output_msg(philo, MSG_FORK);
		output_msg(philo, MSG_EAT);
		philo->t_last_meal = get_time();
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
	return (NULL);
}

static void	launch_process(t_philo *philo)
{
	if (pthread_create(&philo->death, NULL, &death_check, philo))
		exit(output_error("thread create failed\n"));
	sleepeat(philo);
	pthread_join(philo->death, NULL);
	exit(EXIT_SUCCESS);
}

static void	setup_philo(t_table *table, t_philo *philo, int number)
{
	philo->num = number;
	philo->t_last_meal = 0;
	philo->meal_count = 0;
	philo->table = table;
}

int	init_processes(t_table *table)
{
	int	index;

	table->philos = malloc(sizeof(*table->philos) * table->seats);
	if (!table->philos)
	{
		close_semaphores(table);
		return (output_error("malloc 'table->philos' failed\n"));
	}
	index = 0;
	while (index < table->seats)
	{
		setup_philo(table, &table->philos[index], index + 1);
		table->philos[index].pid = fork();
		if (table->philos[index].pid == -1)
		{
			kill_processes(table, index);
			close_semaphores(table);
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
