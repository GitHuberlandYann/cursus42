/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:40:17 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 09:40:17 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	checkout(t_vertice *v, t_vertice *v2)
{
	if (v->x >= 0 && v->x <= WIN_WIDTH && v->y >= 0 && v->y <= WIN_HEIGHT)
		return (0);
	if (v2->x >= 0 && v2->x <= WIN_WIDTH && v2->y >= 0 && v2->y <= WIN_HEIGHT)
		return (0);
	return (1);
}

static void	mlx_link_nodes(t_fdf *fdf, t_vertice *dne, t_vertice *end, int sph)
{
	t_vertice	s;
	t_vertice	e;

	if (!fdf || !dne || !end)
		return ;
	s.x = ft_rotation_x(fdf->angles, dne, fdf->map, sph) * fdf->mlx->size
		+ fdf->mlx->offset_x;
	s.y = ft_rotation_y(fdf->angles, dne, fdf->map, sph) * fdf->mlx->size
		+ fdf->mlx->offset_y;
	s.zcol = dne->z;
	e.x = ft_rotation_x(fdf->angles, end, fdf->map, sph) * fdf->mlx->size
		+ fdf->mlx->offset_x;
	e.y = ft_rotation_y(fdf->angles, end, fdf->map, sph) * fdf->mlx->size
		+ fdf->mlx->offset_y;
	e.z = end->z - dne->z;
	if (sph)
	{
		s.zcol = dne->zcol;
		e.z = end->zcol - dne->zcol;
	}
	if (!checkout(&s, &e))
		mlx_draw_line(fdf, s, e);
}

static void	mlx_link_sphere(t_fdf *fdf, t_vertice *dne, t_vertice *end)
{
	t_vertice	s;
	t_vertice	e;

	if (!fdf || !dne || !end)
		return ;
	plane_to_sphere(fdf->map, &s, dne, fdf->mlx->size);
	plane_to_sphere(fdf->map, &e, end, fdf->mlx->size);
	mlx_link_nodes(fdf, &s, &e, 1);
}

void	plane_to_sphere(t_map *map, t_vertice *spnt, t_vertice *pnt, double size)
{
	t_vertice	rlonlat;

	rlonlat.z = 2 * M_PI * (double)pnt->x / (double)(map->width - 1);
	rlonlat.y = M_PI * (double)pnt->y / (double)(map->height - 1);
	rlonlat.x = (2 - (pnt->z / map->max) * map->ratio) * size * 4;
	spnt->x = rlonlat.x * sin(rlonlat.y) * cos(rlonlat.z);
	spnt->y = rlonlat.x * sin(rlonlat.y) * sin(rlonlat.z);
	spnt->z = rlonlat.x * cos(rlonlat.y);
	spnt->zcol = pnt->z;
}

void	mlx_draw_line(t_fdf *fdf, t_vertice a, t_vertice b)
{
	t_vertice	delta;
	t_vertice	pixel;
	double		len;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	delta.z = delta.y / delta.x;
	len = sqrt(delta.x * delta.x + delta.y * delta.y);
	delta.x /= len;
	delta.y /= len;
	b.z /= len;
	pixel.x = a.x;
	pixel.y = a.y;
	pixel.z = a.zcol;
	while (len > 0)
	{
		mlx_pxl_put(fdf->mlx, pixel, fdf->map->max, fdf->mlx->color_mode);
		pixel.x += delta.x;
		pixel.z += b.z;
		if (delta.x)
			pixel.y = delta.z * (pixel.x - a.x) + a.y;
		else
			pixel.y += delta.y;
		--len;
	}
}

void	mlx_map_img(t_fdf *fdf)
{
	t_face	*tmp;

	if (fdf->mlx->fill)
		return (mlx_fill_faces(fdf));
	tmp = fdf->map->faces;
	while (tmp)
	{
		if (!fdf->mlx->sphere)
		{
			mlx_link_nodes(fdf, tmp->face[1], tmp->face[0], 0);
			mlx_link_nodes(fdf, tmp->face[3], tmp->face[0], 0);
			if ((int)tmp->face[2]->x == fdf->map->width - 1)
				mlx_link_nodes(fdf, tmp->face[3], tmp->face[2], 0);
			if (tmp->face[2]->y == fdf->map->height - 1)
				mlx_link_nodes(fdf, tmp->face[1], tmp->face[2], 0);
		}
		else
		{
			mlx_link_sphere(fdf, tmp->face[1], tmp->face[0]);
			mlx_link_sphere(fdf, tmp->face[3], tmp->face[0]);
		}
		tmp = tmp->next;
	}
}
