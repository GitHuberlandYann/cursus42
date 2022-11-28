/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:46:57 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:48:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_display_vertexes(t_vertex *vert)
{
	ft_putstr("vertexes :\n");
	while (vert)
	{
		printf("%f, %f, %f\n", vert->x, vert->y, vert->z);
		vert = vert->next;
	}
}

static void	ft_display_faces(t_face *face)
{
	ft_putstr("faces :\n");
	while (face)
	{
		printf("%d, %d, %d\n", face->first, face->second, face->third);
		face = face->next;
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac == 2)
	{
		map = get_map(av[1]);
		if (!map)
			return (1);
		ft_display_vertexes(map->vert);
		ft_display_faces(map->faces);
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	return (0);
}
