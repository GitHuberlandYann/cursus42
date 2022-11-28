/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:08:33 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:48:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static float	ft_free_return(char **arr)
{
	int	index;

	if (!arr)
		return (0);
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
	return (0);
}

float	ft_atof(char *str)
{
	float	res;
	char	**sp;

	sp = ft_split(str, '.');
	if (!sp || ft_arraylen(sp) != 2)
		return (ft_free_return(sp));
	res = 0;
	res += ft_atoi(sp[0]);
	res += (float)ft_atoi(sp[1]) / (float)pow(10, ft_strlen(sp[1]));
	return (res);
}
