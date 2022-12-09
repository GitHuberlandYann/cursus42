/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:53:13 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 18:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static void	mlx_link_nodes(t_fdf *fdf, t_vertice *dne, t_vertice *end, int sph)
{
	t_vertice	s;
	t_vertice	e;

	if (!fdf || !dne || !end)
		return ;
	s.x = ft_rotation_x(fdf->angles, dne) * fdf->mlx->size + fdf->mlx->offset_x;
	s.y = ft_rotation_y(fdf->angles, dne) * fdf->mlx->size + fdf->mlx->offset_y;
	s.zcol = dne->z;
	e.x = ft_rotation_x(fdf->angles, end) * fdf->mlx->size + fdf->mlx->offset_x;
	e.y = ft_rotation_y(fdf->angles, end) * fdf->mlx->size + fdf->mlx->offset_y;
	e.z = end->z - dne->z;
	if (sph)
	{
		s.zcol = dne->zcol;
		e.z = end->zcol - dne->zcol;
	}
	mlx_draw_line(fdf, s, e);
}

static void	plane_to_sphere(t_map *map, t_vertice *spnt, t_vertice *pnt)
{
	t_vertice	rlonlat;

	rlonlat.z = 2 * M_PI * (double)pnt->x / (double)(map->width - 1);
	rlonlat.y = M_PI * (double)pnt->y / (double)(map->height - 1);
	rlonlat.x = map->max - pnt->z;
	spnt->x = rlonlat.x * sin(rlonlat.y) * cos(rlonlat.z);
	spnt->y = rlonlat.x * sin(rlonlat.y) * sin(rlonlat.z);
	spnt->z = rlonlat.x * cos(rlonlat.y);
	spnt->zcol = pnt->z;
}

static void	mlx_link_sphere(t_fdf *fdf, t_vertice *dne, t_vertice *end)
{
	t_vertice	s;
	t_vertice	e;

	if (!fdf || !dne || !end)
		return ;
	plane_to_sphere(fdf->map, &s, dne);
	plane_to_sphere(fdf->map, &e, end);
	mlx_link_nodes(fdf, &s, &e, 1);
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
	int		index;

	if (fdf->mlx->fill)
		return (mlx_fill_faces(fdf));
	tmp = fdf->map->faces;
	while (tmp)
	{
		index = 0;
		while (index < 3)
		{
			if (!fdf->mlx->sphere)
				mlx_link_nodes(fdf, tmp->face[index], tmp->face[index + 1], 0);
			else
				mlx_link_sphere(fdf, tmp->face[index], tmp->face[index + 1]);
			++index;
		}
		if (!fdf->mlx->sphere)
			mlx_link_nodes(fdf, tmp->face[index], tmp->face[0], 0);
		else
			mlx_link_sphere(fdf, tmp->face[index], tmp->face[0]);
		tmp = tmp->next;
	}
}
