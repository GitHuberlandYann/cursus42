/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 12:26:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_insert_gnl(char **cmd, char **gnl)
{
	int	index;

	while (cmd[index])
		++index;
	cmd[index] = gnl;
	cmd[index + 1] = 0;
}

void	ft_exec_first_command(char **av, char **envp, char **gnl)
{
	char	**cmd;

	cmd = ft_split_plus(av[2], ' ');
	if (!cmd)
		exit(1);
	cmd[0] = ft_strjoin_free("/bin/", cmd[0]);
	ft_insert_gnl(cmd, gnl);
	execve(cmd[0], &cmd[1], envp);
	printf("program ended with execve, this line should never be read\n");
}
