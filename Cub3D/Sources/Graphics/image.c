/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:31:02 by yhuberla         ###   ########.fr       */
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
	img->bytes_per_pixel = img->bits_per_pixel / 8;
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
		exit(printf("failed to load img |%s| on side %d\n", texture, side)); //exit(printf..);
	else
		img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->bytes_per_pixel = img->bits_per_pixel / 8;
	return (img);
}

void	mlx_clear_img(t_img *img)
{
	t_vert	pt;

	pt.x = 0;
	pt.z = 0;
	while (pt.x < img->width)
	{
		pt.y = 0;
		while (pt.y < img->height)
		{
			mlx_pxl_put(img, pt.x, pt.y, BLACK);
			++pt.y;
		}
		++pt.x;
	}
}

unsigned	mlx_pxl_get(t_img *img, int x, int y)
{
	char	*dst;

	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return (0);
	dst = img->addr + (y * img->line_length + x * img->bytes_per_pixel);
	return (*(unsigned *)dst);
}

void	mlx_pxl_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	// printf("width %d, height %d, x %d, y %d\n", img->width, img->height, x, y);
	dst = img->addr + (y * img->line_length + x * img->bytes_per_pixel);
	*(unsigned *) dst = color;
}

void	mlx_draw_line(t_img *img, t_vert a, t_vert b, unsigned int color)
{
	t_vert	delta;
	t_vert	pixel;
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
		mlx_pxl_put(img, pixel.x, pixel.y, color);
		pixel.x += delta.x;
		if (delta.x)
			pixel.y = delta.z * (pixel.x - a.x) + a.y;
		else
			pixel.y += delta.y;
		--len;
	}
}
