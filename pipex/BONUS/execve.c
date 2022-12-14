/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:56:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	ft_exec_middle_cmd(int index, int pipefd[2], t_env *env)
{
	int	pipefd2[2];

	ft_pipe(&pipefd2);
	if (!env->av[index][0])
	{
		ft_close_pipe(pipefd2);
		return (ft_emptycmd(__LINE__ - 4, __FILE__, __func__));
	}
	env->cmds = ft_split(env->av[index], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	if (!env->cmds[0])
	{
		ft_free_arr(env->cmds, 0);
		env->cmds = ft_split(env->av[index], 'a');
		if (!env->cmds)
			ft_perror(strerror(ENOMEM));
	}
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths);
	if (env->cmds[0])
		ft_exec_forkcmd(pipefd, pipefd2, env);
	ft_free_arr(env->cmds, !env->cmds[0]);
	ft_close_pipe(pipefd);
	pipefd[0] = pipefd2[0];
	pipefd[1] = pipefd2[1];
}

static void	ft_exec_last_cmd(int fdio[2], int pipefd[2], t_env *env)
{
	int	free_index;

	if (!env->av[env->ac - 2][0])
	{
		env->ret = 126;
		return (ft_emptycmd(__LINE__ - 3, __FILE__, __func__));
	}
	env->cmds = ft_split(env->av[env->ac - 2], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	if (!env->cmds[0])
	{
		ft_free_arr(env->cmds, 0);
		env->cmds = ft_split(env->av[env->ac - 2], 'a');
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
	int		index;

	ft_pipe(&pipefd);
	fdio[0] = get_infile(env);
	fdio[1] = -1;
	if (fdio[0] != -1)
		ft_exec_first_cmd(fdio, pipefd, env);
	close(fdio[0]);
	index = 2;
	while (++index < env->ac - 2)
		ft_exec_middle_cmd(index, pipefd, env);
	fdio[1] = get_outfile(env);
	if (fdio[1] == -1)
		ft_perror(env->av[env->ac - 1]);
	ft_exec_last_cmd(fdio, pipefd, env);
	close(fdio[1]);
	if (env->here_doc)
		unlink(".here_doc_tmp");
}
