#include "cub3d.h"

void	render_ground(t_img *img, t_cub *cub, t_vertice *pxl, double alpha)
{
	double		beta;
	double		r;
	double		straight_dist;
	double		dist;
	t_vertice	floor_pt;
	unsigned	color;

	beta = fabs(alpha - cub->map->player->direction);
	while (pxl->y < WIN_HEIGHT)
	{
		r = pxl->y - WIN_HEIGHT / 2;
		straight_dist = WIN_HEIGHT / 2 * cub->mlx->fc_textures[FLOOR]->width / r;
		dist = straight_dist / cos(beta);
		floor_pt.x = cub->map->player->pos.x * cub->mlx->fc_textures[FLOOR]->width + cos(alpha) * dist;
		floor_pt.y = cub->map->player->pos.y * cub->mlx->fc_textures[FLOOR]->width - sin(alpha) * dist;
		color = mlx_pxl_get(cub->mlx->fc_textures[FLOOR], fmod(floor_pt.x, cub->mlx->fc_textures[FLOOR]->width), fmod(floor_pt.y, cub->mlx->fc_textures[FLOOR]->height));
		mlx_pxl_put(img, pxl->x, pxl->y, color);
		if (cub->mlx->fc_textures[CEILLING])
		{
			color = mlx_pxl_get(cub->mlx->fc_textures[CEILLING], fmod(floor_pt.x, cub->mlx->fc_textures[CEILLING]->width), fmod(floor_pt.y, cub->mlx->fc_textures[CEILLING]->height));
			mlx_pxl_put(img, pxl->x, WIN_HEIGHT - pxl->y, color);
		}
		++pxl->y;
	}
}
