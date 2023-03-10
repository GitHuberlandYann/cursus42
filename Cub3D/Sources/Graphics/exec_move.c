#include "cub3d.h"

static void	exec_vmovement(t_ray *ray, t_player *player, t_key *keys, int move)
{
	if (ray->fhit == PORTAL && ray->pdist < player->speed * (1 + keys->sprint)
		&& ray->dist > player->speed * (1 + keys->sprint))
	{
		player->pos.x = ray->pray.pt1.x + cos(ray->out_angle)
			* (player->speed * (1 + keys->sprint));
		player->pos.y = ray->pray.pt1.y - sin(ray->out_angle)
			* (player->speed * (1 + keys->sprint));
		player->direction = ray->out_angle + M_PI * (move == -1);
	}
	else if (ray->mdist > 2 * player->speed * (1 + keys->sprint))
	{
		player->pos.x += cos(player->direction) * player->speed
			* (1 + keys->sprint) * move;
		player->pos.y -= sin(player->direction) * player->speed
			* (1 + keys->sprint) * move;
	}
}

static void	vmove_player(t_key *keys, t_cub *cub, t_player *player)
{
	t_ray	wall_sensor;

	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	wall_sensor.fhit = CUT;
	set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
	wall_sensor.angle = player->direction + M_PI * (keys->vertical == -1);
	wall_sensor.out_angle = wall_sensor.angle;
	wall_sensor.objs = 0;
	ray_walling(cub->map->walls, &wall_sensor);
	ray_dooring(cub->map->doors, &wall_sensor);
	ray_posting(cub->map->posts, &wall_sensor);
	ray_portaling(cub->map->portals, &wall_sensor, 0, cub);
	ray_objing(cub->map->objs, player->other, &wall_sensor);
	exec_vmovement(&wall_sensor, player, keys, keys->vertical);
}

static void	exec_hmovement(t_ray *ray, t_player *player, t_key *keys, int move)
{
	if (ray->fhit == PORTAL && ray->pdist < player->speed * (1 + keys->sprint)
		&& ray->dist > player->speed * (1 + keys->sprint))
	{
		player->pos.x = ray->pray.pt1.x + cos(ray->out_angle)
			* (player->speed * (1 + keys->sprint));
		player->pos.y = ray->pray.pt1.y - sin(ray->out_angle)
			* (player->speed * (1 + keys->sprint));
		player->direction = ray->out_angle + M_PI / 2 + M_PI * (move == 1);
	}
	else if (ray->mdist > 2 * player->speed * (1 + keys->sprint))
	{
		player->pos.x += cos(player->direction + M_PI / 2) * player->speed
			* (1 + keys->sprint) * move;
		player->pos.y -= sin(player->direction + M_PI / 2) * player->speed
			* (1 + keys->sprint) * move;
	}
}

static void	hmove_player(t_key *keys, t_cub *cub, t_player *player)
{
	t_ray	wall_sensor;

	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	wall_sensor.fhit = CUT;
	set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
	wall_sensor.angle = player->direction + M_PI / 2 * keys->horizontal;
	wall_sensor.out_angle = wall_sensor.angle;
	wall_sensor.objs = 0;
	ray_walling(cub->map->walls, &wall_sensor);
	ray_dooring(cub->map->doors, &wall_sensor);
	ray_posting(cub->map->posts, &wall_sensor);
	ray_portaling(cub->map->portals, &wall_sensor, 0, cub);
	ray_objing(cub->map->objs, player->other, &wall_sensor);
	exec_hmovement(&wall_sensor, player, keys, keys->horizontal);
}

void	move_player(t_key *keys, t_cub *cub, t_player *player)
{
	if (keys->vertical)
		vmove_player(keys, cub, player);
	if (keys->horizontal)
		hmove_player(keys, cub, player);
}
