/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/23 17:53:04 by yhuberla         ###   ########.fr       */
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

static void	angles_init(t_angles *a, float alpha, float beta, float gamma)
{
	a->alpha = (alpha * M_PI) / 180;
	a->beta = (beta * M_PI) / 180;
	a->gamma = (gamma * M_PI) / 180;
	a->sa = sin(a->alpha);
	a->ca = cos(a->alpha);
	a->sb = sin(a->beta);
	a->cb = cos(a->beta);
	a->sg = sin(a->gamma);
	a->cg = cos(a->gamma);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = malloc(sizeof(*fdf));
		if (!fdf)
			return (-1);
		fdf->angles = malloc(sizeof(*fdf->angles));
		if (!fdf->angles)
			exit(EXIT_FAILURE);
		angles_init(fdf->angles, ISO_ALPHA, ISO_BETA, ISO_GAMMA);
		if (!fdf->angles)
			return (-1);
		ft_rotation_x(fdf->angles, 100, 100, 100);
		fdf->map = get_map(av[1]);
		if (!fdf->map)
			return (ft_free_return(fdf->angles, 0));
		ft_display_map_content(fdf->map);
		mlx_related_stuff(fdf, av[1]);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	return (0);
}
