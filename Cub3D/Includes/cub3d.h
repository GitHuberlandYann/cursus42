/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 15:33:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Includes
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../Libft/libft.h"
# include "../mlx/mlx.h"

// Macros
# define MSG_ARGS "Usage :  ./cub3D maps/<insert map name>.cub\n"
# define MSG_MAP " -> invalid map\n"
# define MSG_PREFIX "Map should start with 'maps/'"
# define MSG_SUFFIX "Map should end with '.cub'"
# define MSG_OPEN "Open failed"
# define MSG_TWONO "Two different lines start with 'NO'"
# define MSG_TWOSO "Two different lines start with 'SO'"
# define MSG_TWOWE "Two different lines start with 'WE'"
# define MSG_TWOEA "Two different lines start with 'EA'"
# define MSG_INVALIDCHAR "Invalid char found in map"
# define MSG_NOPLAYER "No player found in map"
# define MSG_ONEPORTAL "Only one portal in map"
# define MSG_NOREACHPORTAL "Impossible to reach portals"
# define MSG_UNCLOSED "Map isn't closed"
# define MSG_TOOMANYPLAYERS "More than 1 player in map"
# define MSG_TOOMANYPORTALS "More than 2 portals in map"

# if __linux__
#  define WIN_WIDTH 1800
#  define WIN_HEIGHT 900
#  define MINIMAP_WIDTH 800
# else
#  define WIN_WIDTH 2560
#  define WIN_HEIGHT 1400
#  define MINIMAP_WIDTH 1200
# endif

# define WHITE 0xffffff
# define LIGHT_WHITE 0x949494
# define BLACK 0x0
# define RED 0xff0000

// Enums
typedef enum e_side {
	NO,
	SO,
	WE,
	EA,
	CUT
}			t_side;

typedef enum e_ground {
	FLOOR,
	CEILLING
}			t_ground;

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

# if __linux__
enum {
	KEY_A = 113,
	KEY_D = 100,
	KEY_M = 109,
	KEY_S = 115,
	KEY_W = 122,
	KEY_ESC = 65307,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_SHIFT = 65505,
	KEY_0 = 65438,
	KEY_1 = 65436,
	KEY_2 = 65433,
	KEY_3 = 65435,
	KEY_ASTERISK = 65450,
	KEY_PLUS_PAD = 65451,
	KEY_MINUS_PAD = 65453
};
# else
enum {
	KEY_A = 0,
	KEY_D = 2,
	KEY_M = 46,
	KEY_S = 1,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_SHIFT = 0,// TODO
	KEY_0 = 82,
	KEY_1 = 83,
	KEY_2 = 84,
	KEY_3 = 85,
	KEY_ASTERISK = 67,
	KEY_PLUS_PAD = 69,
	KEY_MINUS_PAD = 78
};
# endif

// Structures
typedef struct s_vertice
{
	double				x;
	double				y;
	double				z;
}				t_vertice;

typedef struct s_player {
	t_vertice	pos;
	double	direction;
	double	size;
	double	speed;
}				t_player;

typedef struct s_parsing {
	int					player_count;
	int					portal_count;
	char				*line;
	int					line_number;
	int					size;
	struct s_parsing	*prev;
	struct s_parsing	*next;
	struct s_parsing	*last;
	struct s_parsing	*player_line;
	struct s_parsing	*(portal_line[2]);
}				t_parsing;

typedef struct s_line {
	t_vertice	pt1;
	t_vertice	pt2;
	t_side		side;
}				t_line;

typedef struct s_wall {
	int				x;
	int				y;
	t_line			edges[4];
	struct s_wall	*next;
	struct s_wall	*last;
}				t_wall;

typedef struct s_map {
	int				player_count;
	t_player		*player;
	t_wall			*walls;
	int				portal_count;
	t_line			portals[2];
	char			*line;
	char			*(textures[4]);
	unsigned int	fc_colors[2];
	int				o_left;
	int				o_right;
	int				o_up;
	int				o_down;
	int				map_width;
	int				map_height;
	double			wall_width;
}				t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_key {
	int	vertical;
	int	horizontal;
	int	sprint;
	int	steering;
	int	fov_width;
	int	fov_enable;
	int	fov_dist;
	int	mini_follow;
	int	mousedate;
}				t_key;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*minimap;
	t_img		*(textures[4]);
	t_key		*keys;
	t_vertice	mouse_pos;
}				t_mlx;

typedef struct s_settings {
	double	fov_width;
	int		fov_enable;
	double	fov_dist;
	int 	mini_follow;
}				t_settings;

typedef struct s_cub {
	t_map		*map;
	t_mlx		*mlx;
	t_settings	*settings;
}				t_cub;

//Graphics
void		launch_mlx(t_map *map, char	*title);
void		fill_minimap(t_cub *cub);
void		fill_minimap_follow(t_cub *cub);

t_img		*ft_create_img(t_mlx *mlx, int width, int height);
void		mlx_clear_img(t_img *img);
void		mlx_draw_line(t_img *img, t_vertice a, t_vertice b, unsigned int color);
void		mlx_pxl_put(t_img *img, t_vertice pt, unsigned int color);

int			key_down(int kcode, t_cub *cub);
int			key_released(int kcode, t_cub *cub);
int			mouse_move(int x, int y, t_cub *cub);
int			redraw_all(t_cub *cub);
int			mlx_exit(void *param);

t_vertice	ray_walling(t_player *player, t_wall *walls, double angle, t_settings *settings);
double		get_dist(t_vertice pt1, t_vertice pt2);
void		set_point(t_vertice *pt, double x, double y, double z);
void		set_point_follow(t_vertice *pt, t_vertice *pt2, t_map *map, int scale);
double		get_min(double a, double b);

// Outputs
int			output_error(char *msg);
void		console_map_content(t_map *map);

// Parsing
int			load_map(t_map *map, char *file);
int			line_from_map(char *str, int empty_allowed);
int			read_first_lines(t_map *map, int fd);
int			transform_color(t_map *map, t_ground ground);
int			read_map(t_map *map, int fd);
int			flood_fill(t_parsing *current, int index, int *portals);
int			free_return_lines(t_parsing *lines, t_map *map);
void		create_walls(t_map *map, t_parsing *lines);

#endif
