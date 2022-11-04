/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 11:16:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_first_command(char **av, char **envp)
{
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	if (!cmd)
		exit(1);
	cmd[0] = ft_strjoin_free("bin/", cmd[0]);
	execve(cmd[0], &cmd[1], envp);
	printf("program ended with execve, this line should never be read\n");
}
