/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:05:12 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 13:05:12 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atod_decimals(char *line, int *index, double *number)
{
	int		len;
	int		deci;

	++(*index);
	deci = 0;
	len = 0;
	while (line[*index] >= '0' && line[*index] <= '9')
	{
		deci = 10 * deci + line[*index] - '0';
		++len;
		++(*index);
		if (deci > 255)
			return (output_error(MSG_FDFDECI255));
	}
	if (!len)
		return (output_error(MSG_FDFDECIUNSET));
	*number += deci / pow(10, len);
	return (0);
}

static double	ft_atod(char *line, int *index, int sindex)
{
	double	number;

	if (line[*index] == '0' && !ft_strchr(" .,\n", line[*index + 1]))
		return (output_error(MSG_FDFZEROPAD) - 1);
	number = 0;
	while (line[*index] >= '0' && line[*index] <= '9')
	{
		number = 10 * number + line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_FDF255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_FDFUNSET) - 1);
	if (line[*index] != '.')
		return (output_error(MSG_FDFDOT) - 1);
	if (ft_atod_decimals(line, index, &number))
		return (0);
	if (line[*index] == ',' && line[*index + 1] >= '0'
		&& line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_FDFZERO) - 1);
	return (number);
}

int	load_pos(char *line, t_fdf *res)
{
	int	index;

	index = 4;
	res->pos.x = ft_atod(line, &index, index);
	if (!res->pos.x)
		return (0);
	res->pos.y = ft_atod(line, &index, index);
	if (!res->pos.y)
		return (0);
	res->pos.z = 0;
	res->pos.next = 0;
	if (line[index] != ' ')
		return (output_error(MSG_FDFEND) - 1);
	return (index + 1);
}
