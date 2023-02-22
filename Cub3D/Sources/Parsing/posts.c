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
			return (output_error(MSG_POSTDECI255));
	}
	if (!len)
		return (output_error(MSG_POSTDECIUNSET));
	*number += deci / pow(10, len);
	return (0);
}

static double	ft_atod(t_map *map, int *index, int sindex)
{
	double	number;

	if (map->line[*index] == '0' && !ft_strchr(" .,\n", map->line[*index + 1]))
		return (output_error(MSG_POSTZEROPAD) - 1);
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_POST255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_POSTUNSET) - 1);
	if (map->line[*index] != '.')
		return (output_error(MSG_POSTDOT) - 1);
	if (ft_atod_decimals(map, index, &number))
		return (0);
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_POSTZERO) - 1);
	return (number);
}

static t_post	*new_post(double x, double y, double radius)
{
	t_post	*res;

	res = ft_malloc(sizeof(*res), "add_post");
	set_point(&res->center, x, y, 0);
	res->radius = radius;
	set_point(&res->squared, x * x, y * y, radius * radius);
	res->next = 0;
	res->last = 0;
	return (res);
}

int	add_post(t_map *map)
{
	double	x;
	double	y;
	double	radius;
	int		index;

	index = 5;
	x = ft_atod(map, &index, index);
	if (!x)
		return (1);
	y = ft_atod(map, &index, index);
	if (!y)
		return (1);
	radius = ft_atod(map, &index, index);
	if (!radius)
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_POSTEND));
	if (!map->posts)
	{
		map->posts = new_post(x, y, radius);
		map->posts->last = map->posts;
	}
	else
	{
		map->posts->last->next = new_post(x, y, radius);
		map->posts->last = map->posts->last->next;
	}
	return (0);
}
