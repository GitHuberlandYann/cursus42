/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/21 17:00:16 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <fcntl.h>

char	**get_map(void)
{
	char	**res;
	int		fd;

	fd = open("maps/42.fdf", O_RDONLY);
	if (fd)
	{
		close(fd);
	}
	res = 0;
	return (res);
}
