/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:55 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/27 16:23:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_check_files(char **av)
{
	if (access(av[1], W_OK)) // ->return -1 on error, and sets errno
		ft_perror(av[1]);
	else if (access(av[4], R_OK))
		ft_perror(av[4]);
	// else
	// 	printf("no problemo\n");
}

// static char	**ft_set_env(void)
// {
// 	char	**res;

// 	res = malloc(sizeof(*res) * 2);
// 	if (!res)
// 		ft_perror(strerror(ENOMEM));
// 	res[0] = malloc(sizeof(*res[0]) * 2);
// 	if (!res[0])
// 		ft_perror(strerror(ENOMEM));
// 	res[0][0] = '.';
// 	res[0][1] = '\0';
// 	res[1] = NULL;
// 	return (res);
// }

// static void	ft_print_arr(char **arr)
// {
// 	int	index;

// 	index = 0;
// 	while (arr[index])
// 	{
// 		ft_putstr_fd(arr[index++], 1);
// 		ft_putstr_fd("\n", 1);
// 	}
// }

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
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

	if (ac >= 5)
	{
		ft_check_files(av);
		env.ac = ac;
		env.av = av;
		env.envp = envp;
		env.paths = ft_get_paths(envp);
		ft_testing_ground(&env);
		ft_free_arr(env.paths);
	}
	else
		printf("wrong number of ac, yours : %d\n", ac);
	// env.paths = ft_get_paths(envp);
	// ft_print_arr(env.paths);
	// ft_free_arr(env.paths);
	return (0);
}
