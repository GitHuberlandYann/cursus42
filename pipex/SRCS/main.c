/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:55 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/01 15:26:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_check_file(char *path, int fd)
{
	char	*itoa_out;
	char	*joins;

	if (access(path, R_OK))
	{
		write(fd, "0\n", 2); //incorrect, need to exec com2 and put output in oufile instead
		itoa_out = ft_itoa(__LINE__ - 2);
		joins = ft_strjoins(7, __FILE__, ": ", __func__, ": line ", itoa_out,
							": ", path);
		free(itoa_out);
		ft_perror(joins);
	}
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_perror_cmd(char *str)
{
	write(2, str, ft_strlen(str));
	exit(127);
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
	int		fd;

	if (ac >= 5)
	{
		fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT);
		if (fd == -1)
			ft_perror(av[4]);
		ft_check_file(av[1], fd);
		env.ac = ac;
		env.av = av;
		env.envp = envp;
		env.paths = ft_get_paths(envp);
		ft_testing_ground(&env, fd);
		ft_free_arr(env.paths);
	}
	else
	{
		printf("wrong number of ac, yours : %d\n", ac);
		return (1);
	}
	return (0);
}
