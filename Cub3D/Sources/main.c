/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:53:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 09:54:53 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (output_error(MSG_ARGS));
	if (load_map(&map, av[1]))
		return (output_error(MSG_MAP));
	// console_map_content(&map);
	launch_mlx(&map, av[1]);
	return (0);
}
