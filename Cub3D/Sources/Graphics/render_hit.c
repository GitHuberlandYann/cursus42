/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:25:11 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 10:40:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_other_hit(t_img *img, t_ray *ray, t_cub *cub, t_vert *start)
{
	if (ray->hit == NO)
		draw_wall_vert(img, start, cub->mlx->textures[NO], ray->u);
	else if (ray->hit == SO)
		draw_wall_vert(img, start, cub->mlx->textures[SO], ray->u);
	else if (ray->hit == WE)
		draw_wall_vert(img, start, cub->mlx->textures[WE], ray->u);
	else if (ray->hit == EA)
		draw_wall_vert(img, start, cub->mlx->textures[EA], ray->u);
	else if (ray->hit == DOOR)
		draw_wall_vert(img, start, cub->mlx->ds_textures[0], ray->u);
	else if (ray->hit == DOORSIDE)
		draw_wall_vert(img, start, cub->mlx->ds_textures[1], ray->u);
	else if (ray->hit == ANIMATED)
		draw_wall_vert(img, start, cub->map->anims->frame, ray->u);
	else if (ray->hit == CIRCLE)
		draw_wall_vert(img, start, cub->mlx->obj_textures[POST], ray->u);
	else if (ray->hit == CUSTOM)
		draw_wall_vert(img, start, cub->mlx->obj_textures[CUST], ray->u);
	else
		return (0);
	return (1);
}

void	draw_hit(t_img *img, t_ray *ray, t_cub *cub)
{
	t_vert	start;
	t_vert	finish;
	double	wall_height;

	ray->dist *= cos(ray->preangle);
	ray->dist *= cub->settings->dist_feel;
	wall_height = 1 / ray->dist;
	set_point(&start, ray->pixel_x, (1 - wall_height) * img->height / 2,
		(1 + wall_height) * img->height / 2);
	set_point(&finish, ray->pixel_x, (1 + wall_height) * img->height / 2, 0);
	if (ray->hit == CUT)
		mlx_draw_line(img, start, finish, GREENISH);
	else if (!draw_other_hit(img, ray, cub, &start))
		set_point(&finish, ray->pixel_x, img->height / 2, 0);
	if (cub->mlx->fc_textures[FLOOR])
		render_ground(img, cub, &finish, ray);
	else if (cub->mlx->fc_textures[CEILLING])
		render_roof(img, cub, &finish, ray);
}
