/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:54:47 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static float	ft_free_return(char **arr)
{
	int	index;

	if (!arr)
		return (0);
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
	return (0);
}

float	ft_atof(char *str)
{
	float	res;
	char	**sp;

	sp = ft_split(str, '.');
	if (!sp || ft_arraylen(sp) != 2)
		return (ft_free_return(sp));
	res = 0;
	res += ft_atoi(sp[0]);
	res += (float)ft_atoi(sp[1]) / (float)pow(10, ft_strlen(sp[1]));
	return (res);
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
