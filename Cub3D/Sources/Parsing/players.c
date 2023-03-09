/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:45:48 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 10:45:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_rays_pixel(t_player *player)
{
	int	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		player->rays[index].pixel_x = index;
		++index;
	}
}

static void	set_player_direction(t_player *player, t_parsing *p_line, int index)
{
	if (p_line->line[index] == 'E')
		player->direction = 0;
	else if (p_line->line[index] == 'N')
		player->direction = M_PI / 2;
	else if (p_line->line[index] == 'W')
		player->direction = M_PI;
	else if (p_line->line[index] == 'S')
		player->direction = -M_PI / 2;
}

static void	init_player(t_map *map, t_parsing *p_line)
{
	int	index;

	map->playerbis = 0;
	map->player = ft_malloc(sizeof(*map->player), __func__);
	index = 0;
	while (p_line->line[index]
		&& !ft_strchr("NSWE", p_line->line[index]))
		++index;
	set_point(&map->player->pos, index, p_line->line_number, 0);
	map->player->state = IDLE;
	map->player->other = 0;
	set_player_direction(map->player, p_line, index);
	set_rays_pixel(map->player);
	map->player->speed = 0.1;
	map->player->obj = ft_malloc(sizeof(*map->player->obj), __func__);
	map->player->obj->type = HUMAN;
	map->player->obj->frame_shoot = 0;
	map->player->obj->fdf = 0;
	map->player->obj->next = 0;
	map->player->obj->last = 0;
}

static void	init_playerbis(t_map *map, t_parsing *p_line)
{
	int	index;

	map->playerbis = ft_malloc(sizeof(*map->playerbis), __func__);
	index = 0;
	while (p_line->line[index])
		++index;
	--index;
	while (index > 0 && !ft_strchr("NSWE", p_line->line[index]))
		--index;
	set_point(&map->playerbis->pos, index, p_line->line_number, 0);
	map->playerbis->state = IDLE;
	map->player->other = map->playerbis;
	map->playerbis->other = map->player;
	set_player_direction(map->playerbis, p_line, index);
	set_rays_pixel(map->playerbis);
	map->playerbis->speed = 0.1;
	map->playerbis->obj = ft_malloc(sizeof(*map->playerbis->obj), __func__);
	map->playerbis->obj->type = HUMAN;
	map->playerbis->obj->frame_shoot = 0;
	map->playerbis->obj->fdf = 0;
	map->playerbis->obj->next = 0;
	map->playerbis->obj->last = 0;
}

void	init_players(t_map *map, t_parsing *lines)
{
	if (map->player_count > 0)
		init_player(map, lines->player_line);
	if (map->player_count == 2)
		init_playerbis(map, lines->playerbis_line);
}
