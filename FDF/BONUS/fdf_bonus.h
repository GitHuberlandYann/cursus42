/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:46:20 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:45:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_vertex
{
	float			x;
	float			y;
	float			z;
	struct s_vertex	*next;
}				t_vertex;

typedef struct s_face
{
	int				first;
	int				second;
	int				third;
	struct s_face	*next;
}				t_face;

typedef struct s_map
{
	t_vertex	*vert;
	t_face		*faces;
	int			nb_vert;
	int			nb_faces;
}				t_map;

t_map	*get_map(char	*path);
void	ft_add_line(t_map *res, char *line);
float	ft_atof(char *str);

void	ft_perror(char *str);
void	ft_free_arr(char **arr);

#endif
