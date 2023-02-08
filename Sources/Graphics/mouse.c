//add header here
#include "cub3d.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	if (!cub->mlx->mouse_pos.z)
	{
		cub->map->player->direction += (cub->mlx->mouse_pos.x - x) / 100;
		cub->mlx->keys->mousedate = 1;
	}	
	set_point(&cub->mlx->mouse_pos, x, y, 0);
	return (0);
}
