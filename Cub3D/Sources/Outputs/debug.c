/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:23:41 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 18:59:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	console_map_content(t_map *map)
{
	printf("\nline     : %s\n", map->line);
	printf("north    : %s\n", map->textures[NO]);
	printf("south    : %s\n", map->textures[SO]);
	printf("west     : %s\n", map->textures[WE]);
	printf("east     : %s\n", map->textures[EA]);
	printf("floor    : %x\n", map->fc_colors[FLOOR]);
	printf("ceilling : %x\n", map->fc_colors[CEILLING]);
}
