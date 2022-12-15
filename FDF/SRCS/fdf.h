/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:33:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 13:59:51 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1400
# define OL_WIDTH 300
# define OL_HEIGHT 300

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
	double				zcol;
	struct s_vertice	*next;
}				t_vertice;

typedef struct s_face
{
	struct	s_vertice	*(face[4]);
	struct s_face		*next;
}				t_face;

typedef struct s_map
{
	t_vertice	*vert;
	t_face		*faces;
	t_vertice	*vert_last;
	t_face		*faces_last;
	int			width;
	int			height;
	double		max;
	double		ratio;
}				t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_img;

typedef struct s_key {
	int	rot_x;
	int	rot_y;
	int	rot_z;
	int	vertical;
	int	horizontal;
	int	zoom;
	int	ratio;
	int	reset_ratio;
	int	rot_special;
	int	color;
	int	overlay;
	int	sphere;
	int	fill;
	int	clevels[6];
}				t_key;

typedef struct s_colors
{
	float	top;
	float	zero;
	float	bottom;
	float	level0;
	float	level1;
	float	level2;
}				t_col;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*back;
	t_img	*overlay;
	t_img	*hex;
	double	size;
	int		offset_x;
	int		offset_y;
	int		color_mode;
	t_key	*key;
	t_col	*col;
	int		sphere;
	int		fill;
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

t_map			*get_map(char	*path);
void			ft_faces_init(t_map *map);

void			ft_perror(const char *str);
void			ft_free_arr(char **arr);
unsigned int	get_color(double z, int max);

int				mlx_related_stuff(t_map *map, t_angles *a, char *title);

void			mlx_pxl_put(t_mlx *mlx, t_vertice pt, int max, int color_mode);
unsigned int	ft_mlx_pixel_get(t_img *img, int x, int y);
void			mlx_map_img(t_fdf *fdf);
void			mlx_fill_faces(t_fdf *fdf);
void			mlx_draw_line(t_fdf *fdf, t_vertice a, t_vertice b);
void			plane_to_sphere(t_map *map, t_vertice *spnt, t_vertice *pnt);

double			set_len(t_vertice *delta, t_vertice *deltc);
void			set_points(t_vertice *sa, t_vertice *sc, t_vertice a,
					t_vertice c);
void			set_delta(t_vertice *delta, t_vertice s, t_vertice e);
void			set_cols(t_vertice *a, t_vertice *b, t_vertice *c, double len);
t_vertice		set_vert(t_fdf *fdf, t_vertice *v, int sph);

double			ft_rotation_x(t_angles *a, t_vertice *node, t_map *map);
double			ft_rotation_y(t_angles *a, t_vertice *node, t_map *map);

void			ft_create_hexa(t_mlx *mlx);
void			ft_create_backimg(t_mlx *mlx);
void			mlx_set_keys(t_mlx *mlx);
void			ft_create_overlay(t_mlx *mlx);

int				mlx_exit(void *param);
int				mouse_button_pressed(int button, int x, int y, t_fdf *fdf);
int				key_down(int keycode, t_fdf *fdf);
int				key_released(int keycode, t_fdf *fdf);
int				mlx_draw(t_fdf *fdf);

#endif
