/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:08:25 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 12:08:25 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_read_file(char *path)
{
	int		fd;
	char	*line;
	char	*res;
	char	*res_save;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	res = 0;
	while (line)	//what if error in gnl ??? -> todo
	{
		res_save = res;
		res = ft_strjoin(res, line);
		free(res_save);
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}
