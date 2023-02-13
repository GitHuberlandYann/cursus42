/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/13 11:30:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Includes
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

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
# define MSG_TWOFT "Two different lines start with 'FT'"
# define MSG_TWOCT "Two different lines start with 'CT'"
# define MSG_TWODOORS "Two different lines start with 'D'"
# define MSG_TWODOORSIDES "Two different lines start with 'DS'"
# define MSG_RGBZEROPAD "RGB values can't be zero-padded"
# define MSG_RGB255 "RGB values can't be greater than 255"
# define MSG_RGBUNSET "Unset or incorrect RGB value"
# define MSG_FCEND "F/C line has unwanted elements ending it"
# define MSG_LINKZEROPAD "Portal index can't be zero-padded"
# define MSG_LINK255 "Portal index can't go above 255"
# define MSG_LINKUNSET "Unset or incorrect portal index"
# define MSG_LINKEND "LINK line has unwanted elements ending it"
# define MSG_INVALIDCHAR "Invalid char found in map"
# define MSG_NOPLAYER "No player found in map"
# define MSG_DOOR_BORDER "Doors can't be at border of map"
# define MSG_CENTER_DOOR "Doors must be between two walls and be accessible from both sides"
# define MSG_PORTAL_BORDER "Portals can't be at border of map"
# define MSG_CENTER_PORTAL "Portals must be between exactly three walls"
# define MSG_UNCLOSED "Map isn't closed"
# define MSG_UNCLOSEDPORTAL "Portal leads to unclosed room"
# define MSG_TOOMANYPLAYERS "More than 1 player in map"
# define MSG_NOLINK "Link missing for one of the portals"
# define MSG_UNUSEDLINK "No portal matching one of the links"
# define MSG_PORTAL_FLOOR "Map can't have portals and floor textures"
# define MSG_PORTAL_CEILLING "Map can't have portals and ceilling textures"
# define MSG_DOORTEXTURE "Missing D/DS line, no texture for doors"

# if __linux__
#  define WIN_WIDTH 1800
#  define WIN_HEIGHT 900
#  define MAP_RADIUS 150
#  define MINIMAP_WIDTH 800
# else
#  define WIN_WIDTH 1800//2560//1500
#  define WIN_HEIGHT 900//1400//600
#  define MAP_RADIUS 150
#  define MINIMAP_WIDTH 800//1200
# endif

# define WHITE 0xffffff
# define LIGHT_WHITE 0x949494
# define BLACK 0x0
# define RED 0xff0000
# define BROWNISH 0x6e4316
# define BLUEISH 0xC1FF
# define GREENISH 0x26E07

# define PSIZE 5
# define PMSIZE 0.1

// Enums
typedef enum e_side {
	EA,
	NO,
	WE,
	SO,
	DOOR,
	DOORSIDE,
	PORTAL,
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
	KEY_SPACE = 32,
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
	KEY_SHIFT = 257,
	KEY_SPACE = 49,
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
	double		direction;
	double		speed;
}				t_player;

typedef struct s_parsing {
	int					player_count;
	char				*line;
	int					line_number;
	int					size;
	struct s_parsing	*prev;
	struct s_parsing	*next;
	struct s_parsing	*last;
	struct s_parsing	*player_line;
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

typedef struct s_door {
	int				x;
	int				y;
	t_line			edges[3];
	struct s_door	*next;
	struct s_door	*last;
}				t_door;

typedef struct s_portal {
	int				x;
	int				y;
	t_line			pline;
	int				num;
	int				link;
	struct s_portal	*next;
	struct s_portal	*last;
}				t_portal;

typedef struct s_ray
{
	t_line		ray;
	t_line		pray;
	t_side		hit;
	t_side		fhit;
	int			recurse_level;
	double		u;
	double		dist;
	double		pdist;
	double		angle;
	double		out_angle;
	t_portal	*in;
	t_portal	*out;
}				t_ray;

typedef struct s_map {
	int				player_count;
	t_player		*player;
	t_wall			*walls;
	int				hasdoor;
	t_door			*doors;
	int				portal_count;
	t_portal		*portals;
	char			*line;
	char			*(textures[4]);
	unsigned int	fc_colors[2];
	char			*(fc_textures[2]);
	char			*(ds_textures[2]);
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
	int		bytes_per_pixel;
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
	int	dist_feel;
	int	mini_follow;
	int	old_mini_enable;
	int	mousedate;
	int	door;
}				t_key;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*render3d;
	t_img		*old_minimap;
	t_img		*(textures[4]);
	t_img		*(fc_textures[2]);
	t_img		*(ds_textures[2]);
	t_key		*keys;
	t_vertice	mouse_pos;
}				t_mlx;

typedef struct s_settings {
	double		fov_width;
	int			fov_enable;
	double		fov_dist;
	double		dist_feel;
	int 		mini_follow;
	int			old_mini_enable;
	int			recurse_level;
	t_vertice	offset;
	int			timepoint;
}				t_settings;

typedef struct s_cub {
	t_map		*map;
	t_mlx		*mlx;
	t_settings	*settings;
	double		angles[WIN_WIDTH];
}				t_cub;

//Graphics
void		launch_mlx(t_map *map, char	*title);
void		fill_minimap(t_cub *cub);
void		fill_old_minimap(t_cub *cub);

void		clear_render(t_img *canva, unsigned int cols[2], t_cub *cub);
void		render_map(t_img *img, t_player *player, t_map *map, t_cub *cub);
void		setup_rendermap(t_img *canva, t_settings *settings);
void		render_ground(t_img *img, t_cub *cub, t_vertice *pxl, double alpha);

void		add_fps(t_mlx *mlx, t_settings *settings);

t_img		*ft_create_img(t_mlx *mlx, int width, int height);
t_img		*ft_create_xpmimg(t_mlx *mlx, char *textures, t_side side);
void		mlx_clear_img(t_img *img);
void		mlx_draw_line(t_img *img, t_vertice a, t_vertice b, unsigned int color);
void		mlx_pxl_put(t_img *img, int x, int y, unsigned int color);
unsigned int	mlx_pxl_get(t_img *img, int x, int y);

int			key_down(int kcode, t_cub *cub);
int			key_released(int kcode, t_cub *cub);
int			mouse_move(int x, int y, t_cub *cub);
int			redraw_all(t_cub *cub);
int			mlx_exit(void *param);

void		ray_walling(t_wall *walls, t_ray *ray);
void		ray_dooring(t_door *doors, t_ray *ray);
void		ray_portaling(t_portal *portals, t_ray *ray, t_cub *cub);
void		try_door(t_player *player, t_door *doors);
t_vertice	get_inter(t_ray *ray, t_vertice pt2, t_vertice pt3, t_vertice pt4);

double		get_dist(t_vertice pt1, t_vertice pt2);
void		set_point(t_vertice *pt, double x, double y, double z);
void		set_point_follow(t_vertice *pt, t_vertice *pt2, t_map *map, t_settings *settings);
int			in_circle(t_vertice *pt, double x, double y, double radius);
void		set_angles(t_cub *cub);

// Outputs
int			output_error(char *msg);
void		console_map_content(t_map *map);

// Parsing
int			load_map(t_map *map, char *file);
int			line_from_map(char *str, int empty_allowed);
int			read_first_lines(t_map *map, int fd);
int			transform_color(t_map *map, t_ground ground);
int			only_spaces(t_map *map, int index);
int			link_portals(t_map *map);
int			read_map(t_map *map, int fd);
int			flood_fill(t_parsing *current, int index);
int			free_return_lines(t_parsing *lines, t_map *map, int free_player);
void		create_walls(t_map *map, t_parsing *lines);
t_wall		*get_wallat(t_wall *walls, int x, int y);
int			add_door(t_map *map, t_parsing *line, int x, int y);
int			set_portal(t_map *map, t_parsing *line, int x, int y);
int			link_empty(t_map *map);
int			conflict_pt(t_map *map);

#endif
