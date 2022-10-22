/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 13:49:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "Libft/libft.h"

typedef struct s_map
{
	int	**map;
	int maplen;
    int rowlen;
}				t_map;

int		mlx_related_stuff(void);
t_map 	*get_map(char	*path);

void	ft_display_map_content(t_map *res);
void	ft_display_lst_content(t_list *lst);

#endif