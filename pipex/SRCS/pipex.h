/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:57 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:43:38 by yhuberla         ###   ########.fr       */
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

typedef struct s_env
{
	int		ret;
	int		ac;
	char	**av;
	char	**envp;
	char	**paths;
	char	**cmds;
}				t_env;

char	**ft_get_paths(char **envp);
char	*ft_get_cmdpath(char *cmd, char **paths);
void	ft_free_arr(char **arr, int index);
void	ft_wait_child(int pid, int *ret);
void	ft_perror(char *str);

void	ft_exec(t_env *env);

void	ft_pipe(int pipefd[2]);
void	ft_close_pipe(int pipefd[2]);
void	ft_dup2(int pipefd[2], int fd);
void	ft_fork(int *child_pid);
void	ft_emptycmd(int line, char *file, const char func[19]);

#endif