/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:10:39 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 09:52:41 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	index;
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (0);
	index = 0;
	while (index < count * size)
	{
		res[index] = 0;
		index ++;
	}
	return (res);
}
