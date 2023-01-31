/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 20:27:02 by yhuberla         ###   ########.fr       */
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

typedef struct s_wall	t_wall;
struct s_wall {
	int		x;
	int		y;
	t_wall	*next;
};

typedef struct s_map {
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
int			read_first_lines(t_map *map, int fd);
int			transform_color(t_map *map, t_ground ground);
int			read_map(t_map *map, int fd);

#endif
