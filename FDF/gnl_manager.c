/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/21 17:23:35 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <fcntl.h>

char	**get_map(char	*path)
{
	char	*line;
	t_line	*res;
	t_line	tmp;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd)
	{
		line = get_next_line(fd);
		while (line)
		{
			tmp = ft_lstnew(line);
			if (!tmp)
				return (ft_free_return(res));
			ft_lstadd_back(&res, tmp);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (res);
}
