/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/23 14:43:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_free_return(t_angles *angles, t_map *map)
{
	int	index;

	free(angles);
	if (map)
	{
		index = 0;
		while (index < map->maplen)
			free(map->map[index ++]);
		free(map);
	}
	return (-1);
}

int	main(int ac, char **av)
{
	t_angles	*angles;
	t_map		*map;

	if (ac == 2)
	{
		angles = angles_init(ISO_ALPHA, ISO_BETA, ISO_GAMMA);
		if (!angles)
			return (-1);
		ft_rotation_x(angles, 100, 100, 100);
		map = get_map(av[1]);
		if (!map)
			return (ft_free_return(angles, 0));
		ft_display_map_content(map);
		mlx_related_stuff(map, angles);
		ft_free_return(angles, map);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	return (0);
}
