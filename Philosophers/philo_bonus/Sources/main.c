/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:09:14 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 10:09:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	int			index;
	t_table		table;

	if (ac < 5 || ac > 6)
		return (output_error(MSG_ARGS));
	if (parse_input(&table, ac, av))
		return (output_error(MSG_INPUT));
	if (init_semaphores(&table))
		return (output_error(NULL));
	if (init_processes(&table))
		return (output_error(NULL));
	index = -1;
	while (++index < table.seats)
		sem_wait(table.full_belly);
	kill_processes(&table, table.seats);
	close_semaphores(&table, 0);
	return (0);
}
