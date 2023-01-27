/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:23:02 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/27 15:40:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	if (!str1 || !str2)
		return (1);
	index = 0;
	while (str1[index] && str2[index] && str1[index] == str2[index])
		++index;
	return (str1[index] - str2[index]);
}

void	output_msg(t_philo *philo, int ms, char *msg)
{
	pthread_mutex_lock(&philo->table->mailbox);
	if (philo->table->alive)
	{
		printf("%d %d %s\n", ms, philo->num, msg);
		if (!ft_strcmp(msg, MSG_DIE))
		{
			philo->table->alive = 0;
		}
	}
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
