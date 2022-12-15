/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 11:16:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_angles	*angles_init(void)
{
	t_angles	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	res->alpha = (ISO_ALPHA * M_PI) / 180;
	res->beta = (ISO_BETA * M_PI) / 180;
	res->gamma = (ISO_GAMMA * M_PI) / 180;
	res->sa = sin(res->alpha);
	res->ca = cos(res->alpha);
	res->sb = sin(res->beta);
	res->cb = cos(res->beta);
	res->sg = sin(res->gamma);
	res->cg = cos(res->gamma);
	return (res);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_angles	*a;

	if (ac == 2)
	{
		map = get_map(av[1]);
		if (!map)
			return (1);
		a = angles_init();
		mlx_related_stuff(map, a, av[1]);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/string.fdf>\n");
	return (0);
}
