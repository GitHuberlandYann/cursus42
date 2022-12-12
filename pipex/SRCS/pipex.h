/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:57 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/12 10:43:41 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"

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

typedef struct s_env
{
	int		ret;
	int		fd;
	int		ac;
	char	**av;
	char	**envp;
	char	**paths;
	char	**cmds;
}				t_env;

char	**ft_get_paths(char **envp);
char	*ft_get_cmdpath(char *cmd, char **paths, int code);
void	ft_free_arr(char **arr);

void	ft_exec_main_child(t_parent p, t_env *env);
void	ft_exec_first_command(char **av, char **envp, char **gnl);
void	ft_exec_second_cmd(t_parent p, t_env *env);

void	ft_pipe(int pipefd[2]);
void	ft_fork(int	*child_pid);
void	ft_wait_child(t_parent *p, int *ret);
void	ft_perror(char *str);
void	ft_perror_cmd(char *str, int code);
#endif