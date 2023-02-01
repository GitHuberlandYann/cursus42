/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 16:36:41 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_create_img(t_mlx *mlx, int width, int height)
{
	t_img	*img;

	img = ft_malloc(sizeof(*img), __func__);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

void	mlx_pxl_put(t_img *img, t_vertice pt)
{
	char	*dst;
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	// printf("width %d, height %d, x %d, y %d\n", img->width, img->height, x, y);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = 0xffffff;
}

void	mlx_draw_line(t_img *img, t_vertice a, t_vertice b)
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
		mlx_pxl_put(img, pixel);
		pixel.x += delta.x;
		if (delta.x)
			pixel.y = delta.z * (pixel.x - a.x) + a.y;
		else
			pixel.y += delta.y;
		--len;
	}
}
