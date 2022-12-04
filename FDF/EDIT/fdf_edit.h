/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_edit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:39:55 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 13:39:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_EDIT_H
# define FDF_EDIT_H

# include <stdio.h>
# include <math.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080

# define EDIT_WIDTH 300

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

enum {
	KEY_A = 97,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_L = 108,
	KEY_M = 109,
	KEY_Q = 1130,
	KEY_R = 114,
	KEY_S = 115,
	KEY_W = 119,
	KEY_Z = 122,
	KEY_ESC = 6530,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_PLUS_PAD = 65451,
	KEY_MINUS_PAD = 65453
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
	struct s_vertice	*(face[4]);
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
	int			max;
}				t_map;

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
	// int	rot_special;
	int	color;
	int	edit;
	// int	overlay;
}				t_key;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*back;
	t_img	*edit;
	// t_img	*overlay;
	// t_img	*hex;
	int		size;
	int		offset_x;
	int		offset_y;
	int		color_mode;
	t_key	*key;
	int		mx;
	int		my;
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

t_map	*get_map(char	*width, char *height);
void	ft_vert_init(t_map *map);
void	ft_faces_init(t_map *map);

void	ft_perror(const char *str);
t_vertice	*ft_get_node(t_vertice *vert, int index);

void	mlx_related_stuff(t_map *map, t_angles *a, char *title);

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color_mode);
void	mlx_map_img(t_fdf *fdf);
void	ft_create_edit(t_mlx *mlx, t_map *map);
void	mlx_map_edit(t_fdf *fdf);
void	ft_edit_edit(int mode, t_fdf *fdf);

double	ft_rotation_x(t_angles *a, t_vertice *node);
double	ft_rotation_y(t_angles *a, t_vertice *node);

int		mlx_exit(void *param);
int		mlx_update_mouse(int x, int y, void *param);
int		key_down(int keycode, void *param);
int		key_released(int keycode, void *param);
int		mlx_draw(void *param);

#endif