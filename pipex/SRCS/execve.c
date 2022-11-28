/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 13:45:00 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcat(t_parent *child_p, char *path, char **envp)
{
	char		*args[3];

	args[0] = "/bin/cat"; //anything will do, just needs something
						//convention = name of current executable
	args[1] = path;
	args[2] = 0;
	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //CHILD OF CHILD
	{
		//ft_putstr_fd("cat\n", 1);
		dup2(child_p->pipefd[1], 1); //output of cat is input of next cmd
		close(child_p->pipefd[0]);
		close(child_p->pipefd[1]);
		execve(args[0], args, envp);
		ft_perror(args[0]);
	}
	else
	{
		ft_wait_child(*child_p);
		close(child_p->pipefd[1]);
		//ft_putstr_fd("parent in forkcat\n", 1);
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
		//ft_putstr_fd(cmd, 1);
		ft_perror(cmd);
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
		//ft_putstr_fd(cmd, 1);
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
	//ft_putstr_fd("Child doing stuff\n", 1);
	cmd = ft_get_cmdpath(cmds[0], env->paths);
	// ft_putstr_fd(cmd, 1);
	ft_pipe(child_p.pipefd);
	ft_exec_forkcat(&child_p, env->av[1], env->envp);
	ft_exec_forkcmd(&child_p, &p, cmd, cmds, env->envp);
	ft_free_arr(cmds);
	free(cmd);
}

void	ft_exec_second_cmd(t_parent p,t_env *env, int fd)
{
	char		*cmd;
	char		**cmds;
	t_parent	child_p;

	cmds = ft_split(env->av[3], ' ');
	if (!cmds)
		ft_perror(strerror(ENOMEM));
	//ft_putstr_fd("Second cmd\n", 1);
	cmd = ft_get_cmdpath(cmds[0], env->paths);
	ft_pipe(child_p.pipefd);
	ft_exec_forkcmdput(&p, fd, cmd, cmds, env->envp);
	// ft_putstr_fd("Now, we put\n", 1);
	close(child_p.pipefd[1]);
	close(2);
	ft_free_arr(cmds);
	free(cmd);
}
