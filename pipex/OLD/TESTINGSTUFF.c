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

void	ft_testing_ground(t_env *env, int fd)
{
	t_parent	p;

	ft_pipe(p.pipefd);
	ft_fork(&p.c_pid);
	if (!p.c_pid) //CHILD
		ft_exec_main_child(p, env);
	else //PARENT, first wait for child to finish
	{
		ft_wait_child(p);
		ft_exec_second_cmd(p, env, fd);
		//ft_putstr_fd("Parent when fork == 1\n", 1);
		exit(EXIT_SUCCESS);
	}
}
