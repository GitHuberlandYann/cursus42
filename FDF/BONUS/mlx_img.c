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

#include "fdf_bonus.h"

static void	mlx_draw_line(t_fdf *fdf, t_vertice a, t_vertice b)
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
	pixel.x = a.x;
	pixel.y = a.y;
	while (len > 0)
	{
		ft_mlx_pixel_put(fdf->mlx->img, pixel.x, pixel.y, 0xffffff);
		pixel.x += delta.x;
		if (delta.x)
			pixel.y = delta.z * (pixel.x - a.x) + a.y;
		else
			pixel.y += delta.y;
		--len;
	}
}

static void	mlx_link_nodes(t_fdf *fdf, t_vertice *dne, t_vertice *end)
{
	t_vertice	s;
	t_vertice	e;

	if (!fdf || !dne || !end)
		return ;
	s.x = ft_rotation_x(fdf->angles, dne) * fdf->mlx->size + fdf->mlx->offset_x;
	s.y = ft_rotation_y(fdf->angles, dne) * fdf->mlx->size + fdf->mlx->offset_y;
	e.x = ft_rotation_x(fdf->angles, end) * fdf->mlx->size + fdf->mlx->offset_x;
	e.y = ft_rotation_y(fdf->angles, end) * fdf->mlx->size + fdf->mlx->offset_y;
	mlx_draw_line(fdf, s, e);
}

t_vertice	*ft_get_node(t_vertice *vert, int index)
{
	int			count;
	t_vertice	*res;

	res = vert;
	count = 1;
	while (count < index && res)
	{
		res = res->next;
		++count;
	}
	return (res);
}

void	mlx_map_img(t_fdf *fdf)
{
	t_face		*tmp;
	int			index;

	tmp = fdf->map->faces;
	while (tmp)
	{
		index = 0;
		while (index < tmp->poly - 1)
		{
			// if (tmp->face[index] < tmp->face[index + 1])
			// {
			mlx_link_nodes(fdf, &tmp->face[index], &tmp->face[index + 1]);
			// }
			++index;
		}
		mlx_link_nodes(fdf, &tmp->face[index], &tmp->face[0]);
		tmp = tmp->next;
	}
}
