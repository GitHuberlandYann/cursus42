/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:24:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_map	*ft_map_init(void)
{
	t_map	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->vert = 0;
	res->faces = 0;
	res->nb_vert = 0;
	res->nb_faces = 0;
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
