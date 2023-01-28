/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:23:02 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/28 13:20:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	output_msg(t_philo *philo, char *msg)
{
	int	time;

	time = get_time() - philo->table->t_start;
	pthread_mutex_lock(&philo->table->mailbox);
	if (philo->table->alive)
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
