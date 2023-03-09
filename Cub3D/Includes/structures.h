/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:51:18 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:07 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "macros.h"

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

typedef struct s_fdfmap
{
	t_vertice	*vert;
	t_face		*faces;
	t_vertice	*vert_last;
	t_face		*faces_last;
}				t_fdfmap;

typedef struct s_vert
{
	double	x;
	double	y;
	double	z;
}				t_vert;

typedef struct s_parsing {
	int					player_count;
	char				*line;
	int					line_number;
	int					size;
	struct s_parsing	*prev;
	struct s_parsing	*next;
	struct s_parsing	*last;
	struct s_parsing	*player_line;
	struct s_parsing	*playerbis_line;
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

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_vert	atplayer;
}				t_img;

typedef struct s_fdf {
	t_vertice		pos;
	int				size;
	int				offset_x;
	int				offset_y;
	t_angles		angles;
	t_img			*canva;
	t_fdfmap		map;
	struct s_fdf	*next;
	struct s_fdf	*last;
}				t_fdf;

typedef struct s_obj {
	t_objtype		type;
	t_vert			pos;
	t_line			oline;
	int				size;
	double			u;
	double			dist;
	int				angle_index;
	t_state			state;
	int				frame_shoot;
	t_fdf			*fdf;
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

typedef struct s_anim {
	double			frame_count;
	char			*str;
	t_img			*frame;
	struct s_anim	*next;
	struct s_anim	*last;
}				t_anim;

typedef struct s_ray
{
	t_line		ray;
	t_line		pray;
	t_side		hit;
	t_side		fhit;
	int			pixel_x;
	double		u;
	double		dist;
	double		mdist;
	double		pdist;
	double		preangle;
	double		angle;
	double		out_angle;
	t_obj		*objs;
}				t_ray;

typedef struct s_player {
	t_vert			pos;
	int				hp;
	double			direction;
	t_state			state;
	double			speed;
	t_ray			rays[WIN_WIDTH];
	t_obj			*obj;
	struct s_player	*other;
}				t_player;

typedef struct s_map {
	int			player_count;
	t_player	*player;
	t_player	*playerbis;
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
	int			hasanimated;
	t_obj		*objs;
	t_post		*posts;
	char		*line;
	char		*(textures[4]);
	unsigned	fc_colors[2];
	char		*(fc_textures[2]);
	char		*(ds_textures[2]);
	char		*(obj_textures[5]);
	t_anim		*anims;
}				t_map;

typedef struct s_key {
	int	vertical;
	int	verticalbis;
	int	horizontal;
	int	sprint;
	int	sprintbis;
	int	steering;
	int	steeringbis;
	int	shoot;
	int	shootbis;
	int	fov_width;
	int	fov_enable;
	int	fov_dist;
	int	dist_feel;
	int	wall_width;
	int	mini_follow;
	int	mini_enable;
	int	mousedate;
	int	door;
	int	doorbis;
	int	godmode;
}				t_key;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*render3d;
	t_img	*render3dbis;
	t_img	*(textures[4]);
	t_img	*(fc_textures[2]);
	t_img	*(ds_textures[2]);
	t_img	*(obj_textures[5]);
	t_img	*(player_idle[8]);
	t_img	*(player_death[5]);
	t_img	*(avatar[5]);
	t_img	*(player_shoot[4]);
	t_img	*(player_run[8][4]);
	t_img	*gun_idle;
	t_img	*(gun_shoot[4]);
	t_key	*keys;
	t_vert	mouse_pos;
	double	frame_count;
	int		curr_frame;
	int		frame_shoot;
	int		frame_shootbis;
	int		fps;
	char	fpstr[15];
}				t_mlx;

typedef struct s_settings {
	int		fov_width;
	int		fov_enable;
	double	fov_dist;
	double	dist_feel;
	int		mini_follow;
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
}				t_cub;

#endif
