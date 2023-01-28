/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:43:04 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/28 14:49:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		table;

	if (ac < 5 || ac > 6)
		return (output_error(MSG_ARGS));
	if (parse_input(&table, ac, av))
		return (output_error(MSG_INPUT));
	if (init_mutex(&table))
		return (output_error(NULL));
	if (init_threads(&table))
		return (output_error(NULL));
	death_cycle(&table);
	destroy_all_mutex(&table, table.seats);
	destroy_all_threads(&table, table.seats);
	return (0);
}
