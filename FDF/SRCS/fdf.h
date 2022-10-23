/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/23 17:48:25 by yhuberla         ###   ########.fr       */
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

enum { //mouse buttons
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_WHEEL_DOWN = 4,
	MOUSE_WHEEL_UP = 5,
	MOUSE_WHEEL_RIGHT = 6,
	MOUSE_WHEEL_LEFT = 7
};

enum {
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_ESC = 53
};

typedef struct s_map
{
	int	**map;
	int	maplen;
	int	rowlen;
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

typedef struct s_fdf
{
	t_map		*map;
	t_mlx		*mlx;
	t_angles	*angles;
}				t_fdf;

int			ft_rotation_x(t_angles *a, float row, float column, float value);
int			ft_rotation_y(t_angles *a, float row, float column, float value);
float		ft_get_xcase(int column, int nbr, int size_x);
float		ft_get_ycase(int row, int nbr, int size_y);
float		ft_get_vcase(int value, int nbr, int size_y);

int			***ft_mapdup(t_mlx *mlx, t_map *map, t_angles *a);

int			mlx_related_stuff(t_fdf *fdf, char *title);
int			mouse_button_pressed(int button, int x, int y, void *param);
int			key_pressed(int keycode, void *param);
t_map		*get_map(char	*path);
int			mlx_exit(void *param);
void		mlx_display_map(t_fdf *fdf);
void		mlx_fill_background(t_mlx *mlx, int color);

void		ft_display_map_content(t_map *res);
void		ft_display_lst_content(t_list *lst);

#endif