#include "cub3d.h"

static int	ft_atod_decimals(t_map *map, int *index, double *number)
{
	int		len;
	int		deci;

	++(*index);
	deci = 0;
	len = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		deci = 10 * deci + map->line[*index] - '0';
		++len;
		++(*index);
		if (deci > 255)
			return (output_error(MSG_WINDDECI255));
	}
	if (!len)
		return (output_error(MSG_WINDDECIUNSET));
	*number += deci / pow(10, len);
	return (0);
}

static double	ft_atod(t_map *map, int *index, int sindex)
{
	double	number;

	if (map->line[*index] == '0' && !ft_strchr(" .,\n", map->line[*index + 1]))
		return (output_error(MSG_WINDZEROPAD) - 1);
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_WIND255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_WINDUNSET) - 1);
	if (map->line[*index] != '.')
		return (output_error(MSG_WINDDOT) - 1);
	if (ft_atod_decimals(map, index, &number))
		return (0);
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_WINDZERO) - 1);
	return (number);
}

static t_obj	*new_window(t_line line)
{
	t_obj	*res;
	double	size;

	size = (int)get_dist(line.pt1, line.pt2);
	if (!size)
		return (0);
	res = ft_malloc(sizeof(*res), "add_window");
	res->type = WIN;
	line.pt1.z = 0;
	line.pt2.z = 0;
	res->oline = line;
	res->size = size;
	res->next = 0;
	res->last = 0;
	return (res);
}

int	add_window(t_map *map)
{
	t_line	wline;
	int		index;

	index = 5;
	wline.pt1.x = ft_atod(map, &index, index);
	if (!wline.pt1.x)
		return (1);
	wline.pt1.y = ft_atod(map, &index, index);
	if (!wline.pt1.y)
		return (1);
	wline.pt2.x = ft_atod(map, &index, index);
	if (!wline.pt2.x)
		return (1);
	wline.pt2.y = ft_atod(map, &index, index);
	if (!wline.pt2.y)
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_WINDEND));
	if (!map->objs)
	{
		map->objs = new_window(wline);
		if (map->objs)
			map->objs->last = map->objs;
	}
	else
	{
		map->objs->last->next = new_window(wline);
		if (map->objs->last->next)
			map->objs->last = map->objs->last->next;
	}
	return (0);
}
