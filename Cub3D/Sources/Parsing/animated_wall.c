/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:04:23 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 13:04:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	new_anim_north(t_map *map, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->wline.side = ANIMATED;
	res->size = 1;
	set_point(&res->wline.pt1, x + 0.5, y - 0.5, 0);
	set_point(&res->wline.pt2, x - 0.5, y - 0.5, 0);
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

static void	new_anim_south(t_map *map, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->wline.side = ANIMATED;
	res->size = 1;
	set_point(&res->wline.pt1, x - 0.5, y + 0.5, 0);
	set_point(&res->wline.pt2, x + 0.5, y + 0.5, 0);
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

static void	new_anim_west(t_map *map, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->wline.side = ANIMATED;
	res->size = 1;
	set_point(&res->wline.pt1, x - 0.5, y - 0.5, 0);
	set_point(&res->wline.pt2, x - 0.5, y + 0.5, 0);
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

static void	new_anim_east(t_map *map, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->wline.side = ANIMATED;
	res->size = 1;
	set_point(&res->wline.pt1, x + 0.5, y + 0.5, 0);
	set_point(&res->wline.pt2, x + 0.5, y - 0.5, 0);
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

int	add_animated_wall(t_map *map, t_parsing *curr, int x, int y)
{
	if (!map->hasanimated && !map->anims)
		return (output_error(MSG_ANIMTEXTURE));
	if (curr->prev && x && x < curr->prev->size
		&& ft_strchr("0XP", curr->prev->line[x]))
		new_anim_north(map, x, y);
	if (curr->next && x && x < curr->next->size
		&& ft_strchr("0XP", curr->next->line[x]))
		new_anim_south(map, x, y);
	if (x > 1 && curr->prev && curr->next
		&& ft_strchr("0XP", curr->line[x - 1]))
		new_anim_west(map, x, y);
	if (x < curr->size - 1 && curr->prev && curr->next
		&& ft_strchr("0XP", curr->line[x + 1]))
		new_anim_east(map, x, y);
	return (0);
}
