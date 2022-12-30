/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/30 16:48:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_exec_forkcmd(int pipein[2], int pipeout[2], t_env *env, int w)
{
	int pid;

	printf("%s\n", env->cmds[0]);
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

static void	ft_exec_middle_cmd(int index, int pipefd[2], t_env *env)
{
	int	pipefd2[2];

	ft_pipe(pipefd2);
	env->cmds = ft_split(env->av[index], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	if (env->cmds[0])
		ft_exec_forkcmd(pipefd, pipefd2, env, 1);
	ft_free_arr(env->cmds);
	close(pipefd[0]);
	close(pipefd[1]);
	pipefd[0] = pipefd2[0];
	pipefd[1] = pipefd2[1];
}

static void	ft_exec_last_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	env->cmds = ft_split(env->av[env->ac - 2], ' ');
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
	int		index;

	ft_pipe(pipefd);
	fdio[0] = open(env->av[1], O_RDONLY);
	if (fdio[0] != -1)
		ft_exec_first_cmd(fdio, pipefd, env);
	index = 3;
	while (index < env->ac - 2)
	{
		printf("debug\n");
		ft_exec_middle_cmd(index, pipefd, env);
		printf("debug bis\n");
		++index;
	}
	fdio[1] = open(env->av[env->ac - 1], O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	// printf("in : %d, out : %d\n", fdio[0], fdio[1]);
	if (fdio[1] == -1)
		ft_perror(env->av[env->ac - 1]);
	ft_exec_last_cmd(fdio, pipefd, env);
	close(fdio[0]);
	close(fdio[1]);
}
