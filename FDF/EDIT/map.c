/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:37:55 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 13:37:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static t_map	*ft_map_init(char *w, char *h)
{
	t_map	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	res->vert = 0;
	res->faces = 0;
	res->vert_last = 0;
	res->faces_last = 0;
	res->width = ft_atoi(w);
	res->height = ft_atoi(h);
	if (res->width > res->height)
		res->max = res->width;
	else
		res->max = res->height;
	return (res);
}

t_map	*get_map(char *width, char *height)
{
	t_map	*res;

	res = ft_map_init(width, height);
	if (res->width < 2 || res->height < 2)
	{
		ft_putstr("invalid arguments.\n");
		exit(EXIT_FAILURE);
	}
	ft_vert_init(res);
	ft_faces_init(res);
	return (res);
}
