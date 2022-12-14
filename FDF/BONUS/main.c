/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:46:57 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/27 12:43:20 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// static void	ft_display_vertice(t_vertice *vert)
// {
// 	ft_putstr("vertices :\n");
// 	while (vert)
// 	{
// 		printf("v  %lf %lf %lf\n", vert->x, vert->y, vert->z);
// 		vert = vert->next;
// 	}
// }

// static void	ft_display_faces(t_face *face)
// {
// 	int	index;

// 	ft_putstr("faces :\n");
// 	while (face)
// 	{
// 		index = 0;
// 		while (index < face->poly)
// 		{
// 			printf("\tv  %lf %lf %lf\n", face->face[index].x,
					// face->face[index].y, face->face[index].z);
// 			++index;
// 		}
// 		ft_putstr("\n");
// 		face = face->next;
// 	}
// }

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
		a = angles_init();
		mlx_related_stuff(map, a, av[1]);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	return (0);
}
