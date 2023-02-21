/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:03:51 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/21 22:46:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	output_error(char *msg)
{
	int	len;

	if (!msg)
		return (1);
	len = 0;
	while (msg[len])
		++len;
	if (write(2, msg, len) == -1)
		return (-1);
	return (1);
}
