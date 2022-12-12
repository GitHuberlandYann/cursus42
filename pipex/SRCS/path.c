/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:53:53 by marvin            #+#    #+#             */
/*   Updated: 2022/11/27 15:53:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_pathstr(char **envp)
{
	int	index;

	index = 0;
	while (envp[index])
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
			return (&envp[index][5]);
		++index;
	}
	return (0);
}

char	**ft_get_paths(char **envp)
{
	char	**res;
	char	*path;

	if (!envp)
		return (0);
	path = ft_get_pathstr(envp);
	if (!path)
		return (0);
	res = ft_split(path, ':');
	return (res);
}

char	*ft_get_cmdpath(char *cmd, char **paths, int code)
{
	int		index;
	char	*res;
	char	*itoa_out;
	char	*joins;

	index = 0;
	while (paths[index])
	{
		res = ft_strjoins(3, paths[index], "/", cmd);
		if (!access(res, X_OK))
		{
			free(cmd);
			return (res);
		}
		free(res);
		++index;
	}
	itoa_out = ft_itoa(__LINE__ - 8);
	joins = ft_strjoins(8, __FILE__, ": ", __func__, ": line ", itoa_out, ": ",
			cmd, ": command not found\n");
	free(itoa_out);
	ft_free_arr(paths);
	ft_perror_cmd(joins, code);
	return (0);
}
