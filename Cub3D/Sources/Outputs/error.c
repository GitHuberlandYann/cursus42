/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:03:51 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 13:04:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	output_error(char *msg)
{
	int	len;

	if (!msg)
		return (1);
	len = 0;
	while (msg[len])
		++len;
	write(2, msg, len);
	return (1);
}
