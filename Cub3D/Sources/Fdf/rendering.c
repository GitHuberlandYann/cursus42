/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:05:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 13:05:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_link_nodes(t_fdf *fdf, t_vertice *dne, t_vertice *end)
{
	t_vert	s;
	t_vert	e;

	if (!fdf || !dne || !end)
		return ;
	s.x = ft_rotation_x(&fdf->angles, dne) * fdf->size + fdf->offset_x;
	s.y = ft_rotation_y(&fdf->angles, dne) * fdf->size + fdf->offset_y;
	e.x = ft_rotation_x(&fdf->angles, end) * fdf->size + fdf->offset_x;
	e.y = ft_rotation_y(&fdf->angles, end) * fdf->size + fdf->offset_y;
	mlx_draw_line(fdf->canva, s, e, WHITE);
}

static void	mlx_map_img(t_fdf *fdf)
{
	t_face		*tmp;
	int			index;

	tmp = fdf->map.faces;
	while (tmp)
	{
		index = 0;
		while (index < tmp->poly - 1)
		{
			mlx_link_nodes(fdf, &tmp->face[index], &tmp->face[index + 1]);
			++index;
		}
		mlx_link_nodes(fdf, &tmp->face[index], &tmp->face[0]);
		tmp = tmp->next;
	}
}

void	render_fdf(t_obj *objs, t_vert *pos)
{
	double	angle;

	while (objs)
	{
		if (objs->type == FDF)
		{
			mlx_clear_img(objs->fdf->canva, TRANSPARENT);
			angle = atan2((pos->y - objs->fdf->pos.y), (pos->x - objs->fdf->pos.x));
			set_fdfangles(&objs->fdf->angles, 0, angle, M_PI);
			mlx_map_img(objs->fdf);
		}
		objs = objs->next;
	}
}
