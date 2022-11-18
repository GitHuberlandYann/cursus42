/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTINGSTUFF.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:45:35 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/17 12:45:35 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_testing_ground(int ac, char **av, char **envp)
{
	t_parent	p;
	int			fd;

	(void)ac;
	(void)av;
	(void)envp;
	ft_pipe(p.pipefd);
	ft_fork(&p.c_pid);
	if (!p.c_pid) //CHILD
		ft_exec_main_child(p, av, envp);
	else //PARENT, first wait for child to finish
	{
		ft_wait_child(p);
		fd = open(av[4], O_WRONLY);
		ft_exec_second_cmd(p, av, envp, fd);
		ft_putstr_fd("Parent when fork == 1\n", 1);
		exit(EXIT_SUCCESS);
	}
}
