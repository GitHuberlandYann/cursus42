/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:18 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:45:12 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_check_file(char *path)
{
	char	*itoa_out;
	char	*joins;

	if (access(path, R_OK))
	{
		itoa_out = ft_itoa(__LINE__ - 1);
		joins = ft_strjoins(7, __FILE__, ": ", __func__, ": line ", itoa_out,
				": ", path);
		free(itoa_out);
		perror(joins);
		free(joins);
	}
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

void	ft_free_arr(char **arr, int index)
{
	if (!arr)
		return ;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

int	main(int ac, char **av, char **envp)
{
	t_env	env;

	env.ret = 0;
	if (ac >= 5)
	{
		env.ac = ac;
		env.av = av;
		if (!check_here_doc(&env))
			ft_check_file(av[1]);
		env.envp = envp;
		env.paths = ft_get_paths(envp);
		ft_exec(&env);
		ft_free_arr(env.paths, 0);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments.\n", 1);
		return (1);
	}
	return (env.ret);
}
