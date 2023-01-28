//add header here

#include "philo_bonus.h"

void	*death_check(void *arg)
{
	int		index;
	t_philo *philo;

	philo = arg;
	while (1)
	{
		if (philo->t_last_meal
			&& get_time() - philo->t_last_meal >= philo->table->t_die)
		{
			output_msg(philo, MSG_DIE);
			sem_wait(philo->table->mailbox);
			index = -1;
			while (++index < philo->table->seats)
				sem_post(philo->table->full_belly);
			return (NULL);
		}
	}
	return (NULL);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
