/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:50 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/03 18:01:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

//FDF
int			load_map_fdf(t_map *map);
int			load_pos(char *line, t_fdf *res);
void		ft_add_line(t_fdfmap *res, char *line);
t_vertice	*ft_get_node(t_vertice *vert, int index);
void		render_fdf(t_obj *objs, t_vert *pos);

void		set_fdfangles(t_angles *a, double alpha, double beta, double gamma);
double		ft_rotation_x(t_angles *a, t_vertice *node);
double		ft_rotation_y(t_angles *a, t_vertice *node);

//Graphics
void		launch_mlx(t_map *map, char	*title);
void		fill_minimap(t_cub *cub);
void		fill_old_minimap(t_cub *cub);

void		clear_render(t_img *canva, unsigned int cols[2], t_cub *cub);
void		render_map(t_img *img, t_player *player, t_map *map, t_cub *cub);
void		setup_rendermap(t_img *canva, t_set *settings);
void		render_ground(t_img *img, t_cub *cub, t_vert *pxl, double alpha, t_player *player);

int			get_time(void);
void		add_fps(t_mlx *mlx, t_set *settings, t_player *player);

t_img		*ft_create_img(t_mlx *mlx, int width, int height);
t_img		*ft_create_xpmimg(t_mlx *mlx, char *textures, t_side side);
void		mlx_draw_line(t_img *img, t_vert a, t_vert b, unsigned int color);
void		mlx_pxl_put(t_img *img, int x, int y, unsigned int color);
unsigned	mlx_pxl_get(t_img *img, int x, int y);

int			key_down(int kcode, t_cub *cub);
int			key_released(int kcode, t_cub *cub);
int			mouse_move(int x, int y, t_cub *cub);
int			redraw_all(t_cub *cub);
int			mlx_exit(void *param);

double		get_dist(t_vert pt1, t_vert pt2);
void		set_point(t_vert *pt, double x, double y, double z);
void		set_point_follow(t_vert *pt, t_vert *pt2, t_map *map, t_set *settings);
int			in_circle(t_vert *pt, double x, double y, double radius);
void		set_ray_angles(double fov_width, t_player *player, t_player *playerbis);

//MultiPlayer
int			key_down_2p(int kcode, t_cub *cub);
int			key_released_2p(int kcode, t_cub *cub);
int			redraw_all_2p(t_cub *cub);
void		clear_render_2p(t_img *canva, unsigned int cols[2], t_cub *cub);
void		precompute_other_player(t_player *player, t_player *other);

void		load_player_imgs(t_mlx *mlx);

// Outputs
int			output_error(char *msg);
void		console_map_content(t_map *map);

// Parsing
int			read_map(t_map *map, int fd);
int			load_map(t_map *map, char *file);
int			line_from_map(char *str, int empty_allowed);
int			read_first_lines(t_map *map, int fd);
int			flood_fill(t_parsing *current, int index);

int			load_texture_obj(t_map *map, t_objtype type);
int			transform_color(t_map *map, t_ground ground);
int			add_obj(t_map *map, t_objtype type);
int			add_post(t_map *map);

int			only_spaces(t_map *map, int index);
int			free_return_lines(t_parsing *lines, t_map *map, int free_player);
int			free_return_line(char *line);
void		free_textures(t_map *map);

void		create_walls(t_map *map, t_parsing *lines, t_parsing *tmp);
void		new_wall_north(t_map *map, t_parsing *curr, int x, int y);
void		new_wall_south(t_map *map, t_parsing *curr, int x, int y);
void		new_wall_west(t_map *map, t_parsing *curr, int x, int y);
void		new_wall_east(t_map *map, t_parsing *curr, int x, int y);

void		add_wall(t_map *map, t_wall *wall);
int			add_door(t_map *map, t_parsing *line, int x);
int			add_custom(t_map *map);
int			add_window(t_map *map);
int			add_animated_wall(t_map *map, t_parsing *curr, int x);
void		load_frame(t_map *map);

int			set_portal(t_map *map, t_parsing *line, int x);
int			link_portals(t_map *map);
int			link_empty(t_map *map);

//RayCasting
void		precompute_obj_lines(t_vert *pos, t_obj *objs);
void		precompute_floor_ceilling(t_player *player, t_img *(fc_textures[2]));

void		ray_walling(t_wall *walls, t_ray *ray);
void		ray_dooring(t_door *doors, t_ray *ray);
void		ray_portaling(t_portal *portals, t_ray *ray, t_player *other, t_cub *cub);
void		ray_objing(t_obj *objs, t_player *other, t_ray *ray);
void		ray_posting(t_post *posts, t_ray *ray);
t_vert		get_inter(t_ray *ray, t_vert pt2, t_vert pt3, t_vert pt4);

void		try_door(t_player *player, t_door *doors);
void		update_doors(t_door *doors, t_key *key);
void		update_anim_frames(t_map *map, t_mlx *mlx, t_key *keys, int fps);

#endif
