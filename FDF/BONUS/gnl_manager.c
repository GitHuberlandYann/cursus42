/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/30 16:02:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	ft_atolf(char *str)
{
	return (strtod(str, NULL));
	// int		len;
	// double	res;
	// char	**sp;

	// sp = ft_split(str, '.');
	// if (!sp || ft_arraylen(sp) != 2)
	// {
	// 	ft_free_arr(sp);
	// 	return (0);
	// }
	// res = ft_atoi(sp[0]);
	// len = ft_strlen(sp[1]);
	// len -= (sp[1][len - 1] == '\n');
	// if (res >= 0)
	// 	res += (double)ft_atoi(sp[1]) / pow(10, len);
	// else
	// 	res -= (double)ft_atoi(sp[1]) / pow(10, len);
	// ft_free_arr(sp);
	// return (res);
}

static t_map	*ft_map_init(void)
{
	t_map	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->vert = 0;
	res->faces = 0;
	return (res);
}

t_map	*get_map(char	*path)
{
	int		fd;
	t_map	*res;
	char	*line;

	res = ft_map_init();
	if (!res)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror(path);
	line = get_next_line(fd);
	while (line)
	{
		ft_add_line(res, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (res);
}
