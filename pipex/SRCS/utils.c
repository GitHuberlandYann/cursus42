/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:45:02 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/17 12:45:02 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(int pipefd[2])
{
	int	pipe_ret;

	pipe_ret = pipe(pipefd);
	if (pipe_ret == -1)
		ft_perror("pipe");
}

void	ft_fork(int *child_pid)
{
	*child_pid = fork();
	if (*child_pid == -1)
		ft_perror("fork");
}

void	ft_wait_child(t_parent *p, int *ret)
{
	p->c_wait = waitpid(p->c_pid, &p->w_status, 0);
	if (p->c_wait == -1)
		return ;
	// while (!WIFEXITED(p->c_wait) && !WIFSIGNALED(p->c_wait))
	// {
	// 	p->c_wait = waitpid(p->c_pid, &p->w_status, 0);
	// 	if (p->c_wait == -1)
	// 		return ;
	// }
	if (WIFEXITED(p->c_wait) && WEXITSTATUS(p->w_status) && !*ret)
		*ret = WEXITSTATUS(p->w_status);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_perror_cmd(char *str, int code)
{
	write(2, str, ft_strlen(str));
	exit(code);
}
