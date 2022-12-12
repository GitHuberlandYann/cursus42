/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:13 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/12 10:43:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_check_file(char *path, t_env *env)
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
		env->ret = 1;
	}
}

static void	ft_exec(t_env *env)
{
	t_parent	p;

	ft_pipe(p.pipefd);
	ft_fork(&p.c_pid);
	if (!p.c_pid) //CHILD
		ft_exec_main_child(p, env);
	else //PARENT, first wait for child to finish
	{
		env->fd = open(env->av[4], O_WRONLY | O_TRUNC | O_CREAT);
		if (env->fd == -1)
			ft_perror(env->av[4]);
		ft_wait_child(&p, &env->ret);
		ft_exec_second_cmd(p, env);
		//ft_putstr_fd("Parent when fork == 1\n", 1);
	}
}

void	ft_free_arr(char **arr)
{
	int	index;

	if (!arr)
		return ;
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

int	main(int ac, char **av, char **envp)
{
	t_env	env;

	env.ret = 0;
	if (ac == 5)
	{
		ft_check_file(av[1], &env);
		env.ac = ac;
		env.av = av;
		env.envp = envp;
		env.paths = ft_get_paths(envp);
		ft_exec(&env);
		ft_free_arr(env.paths);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments.\n", 1);
		return (1);
	}
	return (env.ret);
}
