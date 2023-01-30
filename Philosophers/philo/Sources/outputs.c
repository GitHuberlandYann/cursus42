/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:23:02 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 16:17:29 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	output_msg(t_philo *philo, char *msg)
{
	int	time;
	int	alive;

	time = get_time() - philo->table->t_start;
	pthread_mutex_lock(&philo->table->mailbox);
	pthread_mutex_lock(&philo->table->var_access);
	alive = philo->table->alive;
	pthread_mutex_unlock(&philo->table->var_access);
	if (alive)
		printf("%d %d %s\n", time, philo->num, msg);
	pthread_mutex_unlock(&philo->table->mailbox);
}

int	output_error(char *msg)
{
	int	len;

	if (!msg)
		return (1);
	len = 0;
	while (msg[len])
		++len;
	write(2, msg, len);
	return (1);
}
