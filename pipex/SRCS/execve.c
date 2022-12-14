/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:44:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcmd(int pipein[2], int pipeout[2], t_env *env)
{
	int	pid;

	ft_fork(&pid);
	if (!pid)
	{
		ft_dup2(pipein, 0);
		ft_close_pipe(pipein);
		ft_dup2(pipeout, 1);
		ft_close_pipe(pipeout);
		execve(env->cmds[0], env->cmds, env->envp);
		ft_perror(env->cmds[0]);
	}
	else
	{
		ft_close_pipe(pipein);
		ft_wait_child(pid, &env->ret);
	}
}

static void	ft_exec_first_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	int	free_index;

	if (!env->av[2][0])
		return (ft_emptycmd(__LINE__ - 1, __FILE__, __func__));
	env->cmds = ft_split(env->av[2], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	if (!env->cmds[0])
	{
		ft_free_arr(env->cmds, 0);
		env->cmds = ft_split(env->av[2], 'a');
		if (!env->cmds)
			ft_perror(strerror(ENOMEM));
	}
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	free_index = !env->cmds[0];
	if (!free_index)
		ft_exec_forkcmd(fdio, pipefd, env);
	ft_free_arr(env->cmds, free_index);
}

static void	ft_exec_second_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	int	free_index;

	if (!env->av[3][0])
	{
		env->ret = 126;
		return (ft_emptycmd(__LINE__ - 3, __FILE__, __func__));
	}
	env->cmds = ft_split(env->av[3], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	if (!env->cmds[0])
	{
		ft_free_arr(env->cmds, 0);
		env->cmds = ft_split(env->av[3], 'a');
		if (!env->cmds)
			ft_perror(strerror(ENOMEM));
	}
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	free_index = !env->cmds[0];
	if (!free_index)
		ft_exec_forkcmd(pipefd, fdio, env);
	else
		env->ret = 127;
	ft_free_arr(env->cmds, free_index);
}

void	ft_exec(t_env *env)
{
	int		pipefd[2];
	int		fdio[2];

	ft_pipe(pipefd);
	fdio[0] = open(env->av[1], O_RDONLY);
	fdio[1] = -1;
	if (fdio[0] != -1)
		ft_exec_first_cmd(fdio, pipefd, env);
	fdio[1] = open(env->av[4], O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fdio[1] == -1)
		ft_perror(env->av[4]);
	ft_exec_second_cmd(fdio, pipefd, env);
	ft_close_pipe(fdio);
}
