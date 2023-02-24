/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:31:02 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 17:10:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_FDFX 1000
# define WIN_FDFY 1000

# define MSG_FDFDF "Failed to open map referenced by FDF line"
# define MSG_FDFEMPTY "Map referenced by FDF line is empty"
# define MSG_FDFVERT "Invalid line 'v' in fdf .obj file"

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

typedef struct s_fdf {
	int				size;
	int				offset_x;
	int				offset_y;
	t_angles		angles;
	t_img			*canva;
	t_fdfmap		map;
	struct s_fdf	*next;
	struct s_fdf	*last;
}				t_fdf;

#endif
