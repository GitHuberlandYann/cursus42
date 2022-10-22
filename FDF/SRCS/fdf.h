/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 19:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../Libft/libft.h"

# define ISO_ALPHA 0
# define ISO_BETA -35.264
# define ISO_GAMMA -45

typedef struct s_map
{
	int	**map;
	int maplen;
    int rowlen;
}				t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	char	*title;
}				t_mlx;

typedef struct s_angles
{
	float	alpha;
	float	beta;
	float	gamma;
	float	sa;
	float	ca;
	float	sb;
	float	cb;
	float	sg;
	float	cg;
}				t_angles;

t_angles	*angles_init(float alpha, float beta, float gamma);
int			ft_rotation_x(t_angles *a, float row, float column, float value);
int			ft_rotation_y(t_angles *a, float row, float column, float value);
float		ft_get_xcase(int row, int nbr, t_mlx *mlx);
float		ft_get_ycase(int column, int nbr, t_mlx *mlx);

int			mlx_related_stuff(void);
t_map 		*get_map(char	*path);

void		ft_display_map_content(t_map *res);
void		ft_display_lst_content(t_list *lst);

#endif
