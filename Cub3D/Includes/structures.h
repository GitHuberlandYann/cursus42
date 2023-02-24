/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:51:18 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 16:35:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "macros.h"
# include "fdf.h"

typedef struct s_vert
{
	double	x;
	double	y;
	double	z;
}				t_vert;

typedef struct s_player {
	t_vert	pos;
	double	direction;
	double	speed;
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
	t_vert	pt1;
	t_vert	pt2;
	t_side	side;
}				t_line;

typedef struct s_wall {
	t_line			wline;
	int				size;
	struct s_wall	*next;
	struct s_wall	*last;
}				t_wall;

typedef struct s_door {
	int				x;
	int				y;
	int				side;
	int				state;
	int				timer;
	t_line			edges[3];
	t_line			door;
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

typedef struct s_obj {
	t_objtype		type;
	t_vert			pos;
	t_line			oline;
	int				size;
	double			u;
	double			dist;
	struct s_obj	*next;
	struct s_obj	*last;
	struct s_obj	*next_ray;
	struct s_obj	*last_ray;
}				t_obj;

typedef struct s_post {
	t_vert			center;
	double			radius;
	t_vert			squared;
	struct s_post	*next;
	struct s_post	*last;
}				t_post;

typedef struct s_ray
{
	t_line		ray;
	t_line		pray;
	t_side		hit;
	t_side		fhit;
	int			recurse_level;
	double		u;
	double		dist;
	double		mdist;
	double		pdist;
	double		preangle;
	double		angle;
	double		out_angle;
	t_obj		*objs;
}				t_ray;

typedef struct s_map {
	int			player_count;
	t_player	*player;
	t_wall		*walls;
	int			hasdoor;
	t_door		*doors;
	int			portal_count;
	t_portal	*portals;
	int			hasbarrel;
	int			haspillar;
	int			haspost;
	int			hascustom;
	int			haswindow;
	t_obj		*objs;
	t_post		*posts;
	t_fdf		*fdf;
	char		*line;
	char		*(textures[4]);
	unsigned	fc_colors[2];
	char		*(fc_textures[2]);
	char		*(ds_textures[2]);
	char		*(obj_textures[5]);
}				t_map;

typedef struct s_key {
	int	vertical;
	int	horizontal;
	int	sprint;
	int	steering;
	int	fov_width;
	int	fov_enable;
	int	fov_dist;
	int	dist_feel;
	int	wall_width;
	int	mini_follow;
	int	mini_enable;
	int	mousedate;
	int	door;
	int	godmode;
}				t_key;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*render3d;
	t_img	*(textures[4]);
	t_img	*(fc_textures[2]);
	t_img	*(ds_textures[2]);
	t_img	*(obj_textures[5]);
	t_key	*keys;
	t_vert	mouse_pos;
	int		fps;
	char	fpstr[15];
}				t_mlx;

typedef struct s_settings {
	int		fov_width;
	int		fov_enable;
	double	fov_dist;
	double	dist_feel;
	int 	mini_follow;
	int		mini_enable;
	double	wall_width;
	double	radius_divww;
	int		recurse_level;
	t_vert	offset;
	int		timepoint;
	int		godmode;
}				t_set;

typedef struct s_cub {
	t_map	*map;
	t_mlx	*mlx;
	t_set	*settings;
	t_ray	rays[WIN_WIDTH];
}				t_cub;

#endif
