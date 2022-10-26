/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/26 18:58:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../Libft/libft.h"
#include "../mlx/mlx.h"

# define WIN_SIZE_X 2560
# define WIN_SIZE_Y 1440
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
	KEY_ESC = 53,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_0 = 82,
	KEY_1 = 83,
	KEY_2 = 84,
	KEY_3 = 85,
	KEY_4 = 86,
	KEY_5 = 87,
	KEY_6 = 88,
	KEY_7 = 89,
	KEY_8 = 91,
	KEY_9 = 92,
	KEY_PLUS_PAD = 69,
	KEY_MINUS_PAD = 78
};

typedef struct s_map
{
	int		**map;
	int		maplen;
	int		rowlen;
	int		max_value;
	float	ratio;
	int		colors_enable;
}				t_map;

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	int		size_x;
	int		size_y;
	int		offset_x;
	int		offset_y;
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
float		ft_get_xcase(float column, float len, float size_x);
float		ft_get_ycase(float row, float len, float size_y);
float		ft_get_vcase(t_map *map, float value, float size_y);

int			***ft_mapdup(t_fdf *fdf);
int			ft_get_color(float value, int white, float ratio);

int			mlx_related_stuff(t_fdf *fdf, char *title);
void		ft_create_img(t_mlx *mlx);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

void		rotation_x(t_fdf * fdf, int rotation);
void		rotation_y(t_fdf * fdf, int rotation);
void		rotation_z(t_fdf * fdf, int rotation);

int			mouse_button_pressed(int button, int x, int y, void *param);
int			key_pressed(int keycode, void *param);
t_map		*get_map(char	*path);
int			mlx_exit(void *param);

void		mlx_map_img(t_fdf *fdf);
void		mlx_clear_img(t_mlx *mlx, int color);

void		ft_display_map_content(t_map *res);
void		ft_display_lst_content(t_list *lst);

#endif
