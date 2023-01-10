/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:38:28 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/09 13:38:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_infile_loop(char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line)
			ft_perror("gnl");
		if (!ft_strncmp(limiter, line, ft_strlen(limiter))
			&& ft_strlen(line) == ft_strlen(limiter) + 1)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
}

int	get_infile(t_env *env)
{
	int		fd;

	if (!env->here_doc)
		return (open(env->av[1], O_RDONLY,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
	fd = open(".here_doc_tmp", O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		ft_perror("here_doc");
	get_infile_loop(env->av[1], fd);
	close(fd);
	fd = open(".here_doc_tmp", O_RDONLY,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		unlink(".here_doc_tmp");
		ft_perror("here_doc");
	}
	return (fd);
}

int	get_outfile(t_env *env)
{
	int	res;

	if (!env->here_doc)
		res = open(env->av[env->ac - 1], O_WRONLY | O_TRUNC | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		res = open(env->av[env->ac - 1], O_WRONLY | O_APPEND | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (res);
}

int	check_here_doc(t_env *env)
{
	if (env->ac < 6)
		env->here_doc = 0;
	else if (!ft_strncmp(env->av[1], "here_doc", 9))
	{
		env->here_doc = 1;
		env->av = &env->av[1];
		--env->ac;
	}
	else
		env->here_doc = 0;
	return (env->here_doc);
}
