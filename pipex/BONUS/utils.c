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

#include "pipex_bonus.h"

void	ft_pipe(int (*pipefd)[2])
{
	int	pipe_ret;

	pipe_ret = pipe(*pipefd);
	if (pipe_ret == -1)
		ft_perror("pipe");
}

void	ft_close_pipe(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	ft_dup2(int pipefd[2], int fd)
{
	int	dup_ret;

	dup_ret = dup2(pipefd[fd], fd);
	if (dup_ret == -1)
		ft_perror("dup2");
}

void	ft_fork(int *child_pid)
{
	*child_pid = fork();
	if (*child_pid == -1)
		ft_perror("fork");
}

void	ft_emptycmd(int line, char *file, const char func[19])
{
	char	*itoa_out;
	char	*joins;

	itoa_out = ft_itoa(line - 1);
	joins = ft_strjoins(6, file, ": ", func, ": line ", itoa_out,
			": ");
	free(itoa_out);
	errno = EACCES;
	perror(joins);
	free(joins);
}
