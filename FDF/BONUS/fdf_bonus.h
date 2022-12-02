/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:46:20 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/02 11:33:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_SIZE_X 2560
# define WIN_SIZE_Y 1400

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

typedef struct s_vertice
{
	double				x;
	double				y;
	double				z;
	struct s_vertice	*next;
}				t_vertice;

typedef struct s_face
{
	int					poly;
	struct s_vertice	face[4];
	struct s_face		*next;
}				t_face;

typedef struct s_map
{
	t_vertice	*vert;
	t_face		*faces;
}				t_map;

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_key {
	int	rot_x;
	int	rot_y;
	int	rot_z;
	int	vertical;
	int	horizontal;
	int	zoom;
	// int	rot_special;
	// int	color;
	// int	overlay;
}				t_key;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	// t_img	*overlay;
	// t_img	*hex;
	int		size;
	int		offset_x;
	int		offset_y;
	t_key	*key;
	// t_col	*col;
}				t_mlx;

typedef struct s_angles
{
	double	alpha;
	double	beta;
	double	gamma;
	double	sa;
	double	ca;
	double	sb;
	double	cb;
	double	sg;
	double	cg;
}				t_angles;

typedef struct s_fdf
{
	t_map		*map;
	t_mlx		*mlx;
	t_angles	*angles;
}				t_fdf;

t_map	*get_map(char	*path);
void	ft_add_line(t_map *res, char *line);
double	ft_atolf(char *str);

void	ft_perror(const char *str);
void	ft_free_arr(char **arr);
void	ft_free_map(t_map *map);

void	mlx_related_stuff(t_map *map, t_angles *a, char *title);

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	mlx_map_img(t_fdf *fdf);
t_vertice	*ft_get_node(t_vertice *vert, int index);

double	ft_rotation_x(t_angles *a, t_vertice *node);
double	ft_rotation_y(t_angles *a, t_vertice *node);

int		mlx_exit(void *param);
int		key_down(int keycode, void *param);
int		key_released(int keycode, void *param);
int		mlx_draw(void *param);
#endif
