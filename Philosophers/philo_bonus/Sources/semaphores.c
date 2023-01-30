/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:09:45 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 10:09:45 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_semaphores(t_table *table, int limit)
{
	if (limit && limit < 1)
		return ;
	sem_close(table->full_belly);
	sem_unlink("/full_belly");
	if (limit && limit < 2)
		return ;
	sem_close(table->forks);
	sem_unlink("/forks");
	if (limit && limit < 3)
		return ;
	sem_close(table->mailbox);
	sem_unlink("/mailbox");
	if (limit && limit < 4)
		return ;
	sem_close(table->var_access);
	sem_unlink("/var_access");
}

int	init_semaphores(t_table *table)
{
	sem_unlink("/full_belly");
	sem_unlink("/forks");
	sem_unlink("/mailbox");
	sem_unlink("/var_access");
	table->full_belly = sem_open("/full_belly", O_CREAT, 0644, 0);
	if (table->full_belly == SEM_FAILED)
		return (output_error("sem_open '/full_belly' failed\n"));
	table->forks = sem_open("/forks", O_CREAT, 0644, table->seats);
	if (table->forks == SEM_FAILED)
	{
		close_semaphores(table, 1);
		return (output_error("sem_open '/forks' failed\n"));
	}
	table->mailbox = sem_open("/mailbox", O_CREAT, 0644, 1);
	if (table->mailbox == SEM_FAILED)
	{
		close_semaphores(table, 2);
		return (output_error("sem_open '/mailbox' failed\n"));
	}
	table->var_access = sem_open("/var_access", O_CREAT, 0644, 1);
	if (table->var_access == SEM_FAILED)
	{
		close_semaphores(table, 3);
		return (output_error("sem_open '/var_access' failed\n"));
	}
	return (0);
}
