/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:35:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 14:55:25 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_return(char **cmd, char **gnl)
{
	free(cmd);
	free(gnl);
	return (NULL);
}

char	**ft_arrayjoin_free(char **cmd, char **gnl)
{
	int		index;
	int		sub_index;
	int		cmdlen;
	int		gnllen;
	char	**res;

	cmdlen = ft_arraylen(cmd);
	gnllen = ft_arraylen(gnl);
	res = malloc(sizeof(*res) * (cmdlen + gnllen + 1));
	if (!res)
		return (ft_free_return(cmd, gnl));
	index = 0;
	while (index < cmdlen)
	{
		res[index] = cmd[index];
		++index;
	}
	sub_index = 0;
	while (sub_index < gnllen)
		res[index++] = gnl[sub_index++];
	res[index] = 0;
	ft_free_return(cmd, gnl);
	return (res);
}
