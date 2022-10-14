/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:18:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 17:04:36 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*ptrs;

	if (!s)
		return ;
	ptrs = s;
	index = 0;
	while (index < n)
	{
		ptrs[index] = 0;
		index ++;
	}
}
