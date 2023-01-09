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

void	ft_fork(int *child_pid)
{
	*child_pid = fork();
	if (*child_pid == -1)
		ft_perror("fork");
}

void	ft_wait_child(int pid, int *ret)
{
	int	wait;
	int	status;

	wait = waitpid(pid, &status, 0);
	if (wait == -1)
		return ;
	if (WIFEXITED(status) && WEXITSTATUS(status) && !*ret)
		*ret = WEXITSTATUS(status);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
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
