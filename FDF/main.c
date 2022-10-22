/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 13:49:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac == 2)
	{
		map = get_map(av[1]);
		ft_display_map_content(map);
		//mlx_related_stuff();
	}
	else
		ft_putstr("Program needs 1 argument of type <maps/*>\n");
	return (0);
}
