/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:44:24 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/30 14:48:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void	ft_free_arr(char **arr);

void	ft_exec(t_env *env);

void	ft_pipe(int pipefd[2]);
void	ft_fork(int *child_pid);
void	ft_wait_child(int pid, int *ret);
void	ft_perror(char *str);

#endif