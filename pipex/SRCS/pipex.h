/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:27:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/16 23:10:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../Libft/libft.h"

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_parent
{
    pid_t	c_pid;
	pid_t	c_wait;
	int		w_status;
	int		pipefd[2]; //[read_fd, write_fd]
}				t_parent;

void	ft_exec_first_command(char **av, char **envp, char **gnl);
char	*ft_read_file(char *path);
void	ft_perror(char *str);

void	ft_testing_ground(int ac, char **av, char **envp);
void	ft_exec_main_child(t_parent p, char **av, char **envp);

void	ft_pipe(int	pipefd[2]);
void	ft_fork(int	*child_pid);
void	ft_wait_child(t_parent p);
#endif
