/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:09:42 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 13:09:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

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

	if (ac == 3)
	{
		map = get_map(av[1], av[2]);
		a = angles_init();
		mlx_related_stuff(map, a, "Edit mode.");
	}
	else
		ft_putstr("Program needs 2 arguments of type <int int>\n");
	return (0);
}
