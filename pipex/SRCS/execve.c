/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/09 17:13:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcat(t_parent *child_p, char *path)
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
		exit(0);
	}
	else
	{
		ft_wait_child(*child_p);
		close(child_p->pipefd[1]);
		// ft_putstr_fd("parent in forkcat\n", 1);
	}
}

static void	ft_exec_forkcmd(t_parent *child_p, t_parent *p, char *cmd, char **cmds, char **envp)
{
	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //child
	{
		dup2(p->pipefd[1], 1); //output of cmd is input of next cmd
		dup2(child_p->pipefd[0], 0); //input of cmd is output of cat done previously
		close(p->pipefd[0]);
		close(child_p->pipefd[1]);
		close(p->pipefd[1]);
		close(child_p->pipefd[0]);
		execve(cmd, cmds, envp);
		ft_perror(cmd);
	}
	else
	{
		ft_wait_child(*child_p);
		close(child_p->pipefd[1]);
	}
}

static void	ft_exec_forkcmdput(t_parent *child_p, int fd, char *cmd, char **cmds, char **envp)
{
	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //child
	{
		dup2(fd, 1); //output of cmd is input of next cmd
		dup2(child_p->pipefd[0], 0); //input of cmd is output of cat done previously
		close(child_p->pipefd[1]);
		close(child_p->pipefd[0]);
		close(fd);
		execve(cmd, cmds, envp);
		ft_perror(cmd);
	}
}

void	ft_exec_main_child(t_parent p, t_env *env)
{
	char		*cmd;
	char		**cmds;
	t_parent	child_p;

	cmds = ft_split(env->av[2], ' ');
	if (!cmds)
		ft_perror(strerror(ENOMEM));
	// ft_putstr_fd("Child doing stuff\n", 1);
	cmd = ft_get_cmdpath(cmds[0], env->paths);
	// ft_putstr_fd(cmd, 1);
	ft_pipe(child_p.pipefd);
	ft_exec_forkcat(&child_p, env->av[1]);
	ft_exec_forkcmd(&child_p, &p, cmd, cmds, env->envp);
	ft_free_arr(cmds);
	free(cmd);
}

void	ft_exec_second_cmd(t_parent p,t_env *env, int fd)
{
	char		*cmd;
	char		**cmds;

	cmds = ft_split(env->av[3], ' ');
	if (!cmds)
		ft_perror(strerror(ENOMEM));
	// ft_putstr_fd("Second cmd\n", 1);
	cmd = ft_get_cmdpath(cmds[0], env->paths);
	// ft_putstr_fd(cmd, 1);
	ft_exec_forkcmdput(&p, fd, cmd, cmds, env->envp);
	// ft_putstr_fd("Now, we put\n", 1);
	ft_free_arr(cmds);
	free(cmd);
}
