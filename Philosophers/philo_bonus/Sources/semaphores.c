//add header here

#include "philo_bonus.h"

int	init_semaphores(t_table *table)
{
	sem_unlink("full_belly");
	sem_unlink("forks");
	sem_unlink("mailbox");
	table->full_belly = sem_open("full_belly", O_CREAT, 0644, 0);
	if (table->full_belly == SEM_FAILED)
		return (output_error("sem_open 'full_belly' failed\n"));
	table->forks = sem_open("forks", O_CREAT, 0644, table->seats);
	if (table->forks == SEM_FAILED)
	{
		sem_close(table->full_belly);
		sem_unlink("full_belly");
		return (output_error("sem_open 'forks' failed\n"));
	}
	table->mailbox = sem_open("mailbox", O_CREAT, 0644, 1);
	if (table->mailbox == SEM_FAILED)
	{
		sem_close(table->full_belly);
		sem_unlink("full_belly");
		sem_close(table->forks);
		sem_unlink("forks");
		return (output_error("sem_open 'mailbox' failed\n"));
	}
	return (0);
}

void	close_semaphores(t_table * table)
{
	sem_close(table->full_belly);
	sem_unlink("full_belly");
	sem_close(table->forks);
	sem_unlink("forks");
	sem_close(table->mailbox);
	sem_unlink("mailbox");
}
