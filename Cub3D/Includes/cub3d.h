/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 15:20:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Includes
# include <unistd.h>
# include <fcntl.h>

// Macros
# define MSG_ARGS "Usage :\n./cub3D maps/<insert map name>.cub\n"
# define MSG_MAP " -> invalid map\n"
# define MSG_PREFIX "Map should start with 'maps/'"
# define MSG_SUFFIX "Map should end with '.cub'"
# define MSG_OPEN "Open failed"


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
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture
	unsigned int	floor_color;
	unsigned int	ceilling_color;
}				t_map;

typedef struct s_settings {
	int	FOV;
}				t_settings;

// Outputs
int		output_error(char *msg);

// Parsing
int		load_map(t_map *map, char *file);

#endif
