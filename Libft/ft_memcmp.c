/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:50:40 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 10:02:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;
	const char	*ptrs1;
	const char	*ptrs2;

	if (n <= 0)
		return (0);
	index = 0;
	ptrs1 = s1;
	ptrs2 = s2;
	while (index < n - 1 && ptrs1[index] == ptrs2[index])
		index ++;
	return ((unsigned char) ptrs1[index] - (unsigned char) ptrs2[index]);
}
