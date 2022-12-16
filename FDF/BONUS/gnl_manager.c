/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/16 16:20:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	ft_atolf(char *str)
{
	return (strtod(str, NULL));
}
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

static t_map	*ft_map_init(void)
{
	t_map	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	res->vert = 0;
	res->faces = 0;
	res->vert_last = 0;
	res->faces_last = 0;
	return (res);
}

t_map	*get_map(char	*path)
{
	int		fd;
	t_map	*res;
	char	*line;

	res = ft_map_init();
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
	if (!res->faces)
		ft_perror("map may be empty");
	return (res);
}
