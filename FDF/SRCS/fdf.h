/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 22:01:44 by marvin           ###   ########.fr       */
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

enum {	//events supported on mac (only a fraction of what can be found on x11)
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
float		ft_get_xcase(int column, int nbr, t_mlx *mlx);
float		ft_get_ycase(int row, int nbr, t_mlx *mlx);

int			***ft_mapdup(t_mlx *mlx, t_map *map, t_angles *a);

int			mlx_related_stuff(void);
int			mouse_button_pressed(int button, int x, int y, void *param);
int			key_pressed(int keycode, void *param);
t_map 		*get_map(char	*path);
void		mlx_exit(void *params);

void		ft_display_map_content(t_map *res);
void		ft_display_lst_content(t_list *lst);

#endif
