/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:09:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 11:14:26 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	output_msg(t_philo *philo, char *msg, int unlock)
{
	int	time;

	time = get_time() - philo->table->t_start;
	sem_wait(philo->table->mailbox);
	printf("%d %d %s\n", time, philo->num, msg);
	if (unlock)
		sem_post(philo->table->mailbox);
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
