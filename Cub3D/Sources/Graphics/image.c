/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/11 15:57:03 by marvin           ###   ########.fr       */
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

t_img	*ft_create_xpmimg(t_mlx *mlx, char *texture, t_side side)
{
	t_img	*img;

	if (!texture)
		return (0);
	img = ft_malloc(sizeof(*img), __func__);
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			texture, &img->width, &img->height);
	if (!img->img_ptr)
		printf("failed to load img |%s| on side %d\n", texture, side); //exit(printf..);
	else
		img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	mlx_clear_img(t_img *img)
{
	t_vertice	pt;

	pt.x = 0;
	pt.z = 0;
	while (pt.x < img->width)
	{
		pt.y = 0;
		while (pt.y < img->height)
		{
			mlx_pxl_put(img, pt, BLACK);
			++pt.y;
		}
		++pt.x;
	}
}

void	mlx_pxl_put(t_img *img, t_vertice pt, unsigned int color)
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
	*(unsigned int *) dst = color;
}

void	mlx_draw_line(t_img *img, t_vertice a, t_vertice b, unsigned int color)
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
		mlx_pxl_put(img, pixel, color);
		pixel.x += delta.x;
		if (delta.x)
			pixel.y = delta.z * (pixel.x - a.x) + a.y;
		else
			pixel.y += delta.y;
		--len;
	}
}
