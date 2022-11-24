/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/24 18:07:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_free_return(t_angles *angles, t_fdf *fdf)
{
	free(angles);
	free(fdf);
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
	
	fdf = malloc(sizeof(*fdf));
	if (!fdf)
		return (-1);
	if (ac == 3)
	{
		fdf->map2 = get_map(av[2]); //need to free this when next mallocs fail -> TODO
		if (!fdf->map2)
			return (-1);
		ac = 2;
	}
	else
		fdf->map2 = 0;
	if (ac == 2)
	{
		fdf->angles = malloc(sizeof(*fdf->angles));
		if (!fdf->angles)
			exit(EXIT_FAILURE);
		angles_init(fdf->angles, ISO_ALPHA, ISO_BETA, ISO_GAMMA);
		fdf->map = get_map(av[1]);
		if (!fdf->map)
			return (ft_free_return(fdf->angles, fdf));
		fdf->map->colors_enable = 1;
		mlx_related_stuff(fdf, av[1]);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	free(fdf);
	return (0);
}
