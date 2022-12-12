/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/12 12:24:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcat(t_parent *child_p, char *path, int *ret)
{
	int		fd;
	char	buf[43];
	int		read_ret;


	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //CHILD OF CHILD
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			ft_perror(path);
		dup2(child_p->pipefd[1], 1); //output of read is input of next cmd
		close(child_p->pipefd[0]);
		close(child_p->pipefd[1]);
		read_ret = read(fd, buf, 42);
		buf[read_ret] = '\0';
		while (read_ret > 0)
		{
			write(1, buf, read_ret);
			read_ret = read(fd, buf, 42);
			buf[read_ret] = '\0';
		}
		close(fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_wait_child(child_p, ret);
		close(child_p->pipefd[1]);
		// ft_putstr_fd("parent in forkcat\n", 1);
	}
}

static void	ft_exec_forkcmd(t_parent *child_p, t_parent *p, t_env *env, int wait)
{
	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //child
	{
		dup2(p->pipefd[1], 1); //output of cmd is input of next cmd
		dup2(child_p->pipefd[0], 0); //input of cmd is output of cmd done previously
		close(p->pipefd[0]);
		close(child_p->pipefd[1]);
		close(p->pipefd[1]);
		close(child_p->pipefd[0]);
		execve(env->cmds[0], env->cmds, env->envp);
		ft_perror(env->cmds[0]);
	}
	else
	{
		if (wait)
			ft_wait_child(child_p, &env->ret);
		close(child_p->pipefd[1]);
	}
}

// static void	ft_exec_forkcmdput(t_parent *child_p, t_parent *p, t_env *env)
// {
// 	ft_fork(&child_p->c_pid);
// 	if (!child_p->c_pid) //child
// 	{
// 		dup2(env->fd, 1); //output of cmd is input of fd
// 		dup2(p->pipefd[0], 0); //input of cmd is output of cmd0 done previously
// 		close(p->pipefd[1]);
// 		close(p->pipefd[0]);
// 		close(env->fd);
// 		execve(env->cmds[0], env->cmds, env->envp);
// 		ft_perror(env->cmds[0]);
// 	}
// 	else
// 	{
// 		printf("\n\n\n\n\n\n\n\n\nberfore\n");
// 		ft_wait_child(child_p, &env->ret);
// 		printf("after\n");
// 	}
// }

void	ft_exec_main_child(t_parent p, t_env *env)
{
	t_parent	child_p;

	env->cmds = ft_split(env->av[2], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	// ft_putstr_fd("Child doing stuff\n", 1);
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths, 0);
	// ft_putstr_fd(cmd, 1);
	ft_pipe(child_p.pipefd);
	ft_exec_forkcat(&child_p, env->av[1], &env->ret);
	ft_exec_forkcmd(&child_p, &p, env, 1);
	ft_free_arr(env->cmds);
}

void	ft_exec_second_cmd(t_parent p, t_env *env)
{
	t_parent	child_p;

	env->cmds = ft_split(env->av[3], ' ');
	if (!env->cmds)
		ft_perror(strerror(ENOMEM));
	// ft_putstr_fd("Second cmd\n", 1);
	env->cmds[0] = ft_get_cmdpath(env->cmds[0], env->paths, 127);
	// ft_putstr_fd(cmd, 1);
	child_p.pipefd[1] = env->fd;
	child_p.pipefd[0] = env->fd;
	ft_exec_forkcmd(&p, &child_p, env, 0);
	// ft_putstr_fd("Now, we put\n", 1);
	ft_free_arr(env->cmds);
}
