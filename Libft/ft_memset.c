/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:47 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 12:00:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*ptrb;

	ptrb = b;
	index = 0;
	while (index < len)
		ptrb[index ++] = (unsigned char) c;
	return (b);
}
