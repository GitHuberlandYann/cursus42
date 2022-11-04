/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:55 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 12:21:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_perror(char *str)
{
	perror(str);
	return (1);
}

static int	ft_check_files(char **av)
{
	if (access(av[1], W_OK)) // ->return -1 on error, and sets errno
		return (ft_perror(av[1]));
	else if (access(av[4], R_OK))
		return (ft_perror(av[4]));
	else
		printf("no problemo\n");
	return (0);
}

static char	**ft_set_env(void)
{
	char	**res;

	res = malloc(sizeof(*res) * 2);
	if (!res)
		return (NULL);
	res[0] = malloc(sizeof(*res[0]) * 2);
	if (!res[0])
	{
		free(res);
		return (NULL);
	}
	res[0][0] = '.';
	res[0][1] = '\0';
	res[1] = NULL;
	return (res);
}

int	main(int ac, char **av)
{
	char	**envp;
	char	**gnl_file1;

	if (ac == 5)
	{
		if (ft_check_files(av))
			return (1);
		envp = ft_set_env();
		if (!envp)
			return (1); // ->print msg of some sort ?
		gnl_file1 = ft_read_file(av[1]);
		ft_exec_first_command(av, envp, gnl_file1);
	}
	else
		printf("wrong number of ac, yours : %d\n", ac);
	return (0);
}
