/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:03:51 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/29 11:50:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	output_error(char *msg)
{
	int	len;

	if (!msg)
		return (1);
	if (ft_strncmp(msg, MSG_MAP, 16))
		write(2, "Error\n", 6);
	len = 0;
	while (msg[len])
		++len;
	if (write(2, msg, len) == -1)
		return (-1);
	return (1);
}
