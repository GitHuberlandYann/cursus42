/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:13 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:26:56 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (ac == 5)
	{
		ft_check_file(av[1]);
		env.ac = ac;
		env.av = av;
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
