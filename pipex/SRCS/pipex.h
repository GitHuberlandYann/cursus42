/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:27:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 12:22:00 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../Libft/libft.h"

# include <stdio.h>
# include <fcntl.h>

void	ft_exec_first_command(char **av, char **envp, char **gnl);
char	**ft_read_file(char *path);

#endif
