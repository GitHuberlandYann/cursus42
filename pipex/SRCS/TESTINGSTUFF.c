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

void	ft_testing_ground(int ac, char **av, char **envp)
{
	t_parent	p;
	char		buf[101];
	int			read_ret;

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
		ft_putstr_fd("Parent when fork == 1\n", 1);
		read_ret = read(p.pipefd[0], buf, 100);
		while (read_ret == 100)
		{
			buf[read_ret] = '\0';
			write(STDOUT_FILENO, buf, 100);
			read_ret = read(p.pipefd[0], buf, 100);
		}
		buf[read_ret] = '\0';
		write(STDOUT_FILENO, buf, ft_strlen(buf));
		exit(EXIT_SUCCESS);
	}
}
