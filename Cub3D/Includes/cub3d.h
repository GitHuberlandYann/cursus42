/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 13:59:06 by yhuberla         ###   ########.fr       */
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
# define MSG_UNCLOSED "Map isn't closed"
# define MSG_TOOMANYPLAYERS "More than 1 player in map"

typedef enum e_side {
	NO,
	SO,
	WE,
	EA
}			t_side;

typedef enum e_ground {
	FLOOR,
	CEILLING
}			t_ground;

// Structures
typedef struct s_player {
	float	x;
	float	y;
	float	z;
	float	direction;
}				t_player;

typedef struct s_parsing {
	int					player_count;
	char				*line;
	int					size;
	struct s_parsing	*prev;
	struct s_parsing	*next;
	struct s_parsing	*last;
	struct s_parsing	*player_line;
}				t_parsing;

typedef struct s_wall {
	int				x;
	int				y;
	struct s_wall	*next;
	struct s_wall	*last;
}				t_wall;

typedef struct s_map {
	int				player_count;
	t_player		*player;
	t_wall			*walls;
	char			*line;
	char			*(textures[4]);
	unsigned int	fc_colors[2];
}				t_map;

typedef struct s_settings {
	int	FOV;
}				t_settings;

// Outputs
int			output_error(char *msg);
void		console_map_content(t_map *map);

// Parsing
int			load_map(t_map *map, char *file);
int			line_from_map(char *str, int empty_allowed);
int			read_first_lines(t_map *map, int fd);
int			transform_color(t_map *map, t_ground ground);
int			read_map(t_map *map, int fd);
int			flood_fill(t_parsing *current, int index);
int			free_return_lines(t_parsing *lines);
void		create_walls(t_map *map, t_parsing *lines);

#endif
