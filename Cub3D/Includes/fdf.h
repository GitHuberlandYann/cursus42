/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:31:02 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/25 16:16:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_FDFX 1000
# define WIN_FDFX_2 500
# define WIN_FDFY 1000
# define WIN_FDFY_2 500

# define MSG_FDFDF "Failed to open map referenced by FDF line"
# define MSG_FDFEMPTY "Map referenced by FDF line is empty"
# define MSG_FDFVERT "Invalid line 'v' in fdf .obj file"
# define MSG_FDFZEROPAD "Fdf double can't be zero-padded"
# define MSG_FDF255 "Fdf double can't be greater than 255"
# define MSG_FDFUNSET "Unset or incorrect Fdf double"
# define MSG_FDFDECI255 "Fdf double's decimal part can't be greater than 255"
# define MSG_FDFDECIUNSET "Unset or incorrect Fdf double's decimal part"
# define MSG_FDFDOT "Missing '.' in Fdf double"
# define MSG_FDFZERO "Object double can't be set at zero"
# define MSG_FDFEND "Fdf line has unwanted elements ending it"

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

#endif
