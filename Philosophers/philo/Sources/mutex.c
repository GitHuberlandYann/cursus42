/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:16:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/27 14:32:52 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all_mutex(t_table *table, int limit)
{
	int	index;

	pthread_mutex_destroy(&table->mailbox);
	index = 0;
	while (index < limit)
	{
		pthread_mutex_destroy(&table->forks[index]);
		++index;
	}
	free(table->forks);
}

int	init_mutex(t_table *table)
{
	int	index;

	if (pthread_mutex_init(&table->mailbox, NULL) != 0)
		return (output_error("mutex init 'mailbox' failed\n"));
	table->forks = malloc(sizeof(*table->forks) * table->seats);
	if (!table->forks)
	{
		pthread_mutex_destroy(&table->mailbox);
		return (output_error("malloc 'table->forks' failed\n"));
	}
	index = 0;
	while (index < table->seats)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != 0)
		{
			destroy_all_mutex(table, index);
			return (output_error("mutex init 'table->forks[index]' failed\n"));
		}
		++index;
	}
	return (0);
}
