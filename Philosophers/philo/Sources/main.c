/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:43:04 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/27 16:04:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_cycle(void *arg)
{
	int		index;
	t_table	*table;

	table = arg;
	while (table->alive)
	{
		index = 0;
		while (index < table->seats)
		{
			
			++index;
		}
	}
	destroy_all_threads(table, table->seats);
	destroy_all_mutex(table, table->seats);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_table		table;
	pthread_t	grim_reaper;

	if (ac < 5 || ac > 6)
		return (output_error(MSG_ARGS));
	if (parse_input(&table, ac, av))
		return (output_error(MSG_INPUT));
	if (init_mutex(&table))
		return (output_error(NULL));
	if (init_threads(&table))
		return (output_error(NULL));
	pthread_create(&grim_reaper, NULL, &death_cycle, &table);
	while (table.alive)
		;
	pthread_join(grim_reaper, NULL);
	return (0);
}
