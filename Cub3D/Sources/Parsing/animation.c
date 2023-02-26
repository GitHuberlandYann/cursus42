#include "cub3d.h"

void	load_frame(t_map *map)
{
	t_anim	*res;

	map->hasanimated = 1;
	res = ft_malloc(sizeof(*res), __func__);
	res->frame_count = 0;
	res->str = ft_strdup(&map->line[6]);
	res->str[ft_strlen(res->str) - 1] = '\0';
	res->next = 0;
	res->last = 0;
	if (!map->anims)
	{
		map->anims = res;
		map->anims->last = res;
	}
	else
	{
		map->anims->last->next = res;
		map->anims->last = res;
	}
}
