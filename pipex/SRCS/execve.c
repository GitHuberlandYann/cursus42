/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/06 13:18:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcmd(int pipein[2], int pipeout[2], t_env *env, int w)
{
	int pid;

	// printf("%s\n", env->cmds[0]);
	ft_fork(&pid);
	if (!pid) //child
	{
		dup2(pipein[0], 0);
		close(pipein[0]);
		close(pipein[1]);
		dup2(pipeout[1], 1);
		close(pipeout[0]);
		close(pipeout[1]);
		execve(env->cmds[0], env->cmds, env->envp);
		ft_perror(env->cmds[0]);
	}
	else
	{
		if (w)
			ft_wait_child(pid, &env->ret);
	}
}

static void	ft_exec_first_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	env->cmds = ft_split(env->av[2], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	if (env->cmds[0])
		ft_exec_forkcmd(fdio, pipefd, env, 1);
	ft_free_arr(env->cmds);
}

static void	ft_exec_second_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	env->cmds = ft_split(env->av[3], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	if (env->cmds[0])
		ft_exec_forkcmd(pipefd, fdio, env, 0);
	else
		env->ret = 127;
	ft_free_arr(env->cmds);
}

void	ft_exec(t_env *env)
{
	int		pipefd[2];
	int		fdio[2];

	ft_pipe(pipefd);
	fdio[0] = open(env->av[1], O_RDONLY);
	fdio[1] = 100;
	if (fdio[0] != -1)
		ft_exec_first_cmd(fdio, pipefd, env);
	fdio[1] = open(env->av[4], O_WRONLY | O_TRUNC | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	// printf("in : %d, out : %d\n", fdio[0], fdio[1]);
	if (fdio[1] == -1)
		ft_perror(env->av[4]);
	ft_exec_second_cmd(fdio, pipefd, env);
	close(fdio[0]);
	close(fdio[1]);
}
