/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/17 13:41:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_forkcat(t_parent *child_p, char *path, char **envp)
{
	char		*args[3];

	args[0] = "/bin/cat"; //anything will do, just needs something,
						//convention = name of current executable
	args[1] = path;
	args[2] = 0;
	ft_fork(&child_p->c_pid);
	if (!child_p->c_pid) //CHILD OF CHILD
	{
		ft_putstr_fd("cat\n", 1);
		dup2(child_p->pipefd[1], 1); //output of cat is input of next cmd
		execve(args[0], args, envp);
		ft_perror(strerror(errno));
	}
	else
	{
		ft_wait_child(*child_p);
		ft_putstr_fd("parent in forkcat\n", 1);
	}
}

void	ft_exec_main_child(t_parent p, char **av, char **envp)
{
	char		*cmd;
	char		**cmds;
	t_parent	child_p;

	(void)p;
	(void)av;
	(void)envp;
	cmds = ft_split(av[2], ' ');
	if (!cmds)
		ft_perror(strerror(ENOMEM));
	ft_putstr_fd("Child doing stuff\n", 1);
	cmd = ft_strjoin("/bin/", cmds[0]);
	if (!cmd)
		ft_perror(strerror(ENOMEM));
	// ft_putstr_fd(cmd, 1);
	ft_pipe(child_p.pipefd);
	ft_exec_forkcat(&child_p, av[1], envp);
	dup2(child_p.pipefd[0], 0);
	dup2(p.pipefd[1], 1); //output of cmd is input of next cmd
	execve(cmd, cmds, envp);
	free(cmd);
	cmd = ft_strjoin("/usr/bin/", cmds[0]);
	if (!cmd)
		ft_perror(strerror(ENOMEM));
	execve(cmd, cmds, envp);
	ft_putstr_fd(cmd, 1);
	ft_perror(cmd);
}

// void	ft_exec_first_command(char **av, char **envp, char **gnl)
// {
// 	char	**cmd;

// 	cmd = ft_split(av[2], ' ');
// 	if (!cmd)
// 		exit(1);
// 	cmd[0] = ft_strjoin_free("/bin/", cmd[0]);
// 	//cmd = ft_arrayjoin_free(cmd, gnl)
// 	(void)gnl;
// 	execve(cmd[0], &cmd[1], envp);
// 	printf("program ended with execve, this line should never be read\n");
// }
