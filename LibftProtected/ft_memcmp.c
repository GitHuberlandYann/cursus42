/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:50:40 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 13:00:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;
	const char	*ptrs1;
	const char	*ptrs2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	index = 0;
	ptrs1 = s1;
	ptrs2 = s2;
	while (index < n - 1 && ptrs1[index] == ptrs2[index])
		index ++;
	return ((unsigned char) ptrs1[index] - (unsigned char) ptrs2[index]);
}
