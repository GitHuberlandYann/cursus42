/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:27:55 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/07 21:08:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../Libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h>

# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define RED "\033[0;31m"
# define WHITE "\033[0m"
# define YELLOW "\033[0;33m"

void	signal_handler(int signo, siginfo_t *info, void *context);

void	lexer(char *rl);
int		check_quotes(char *str);
void	exec_echo(char **lex, char *args);
void	exec_cd(char **lex);
void	display_pwd(void);

void	set_col(char *col);
void	greet_user(void);
void	close_program(void);

void	ft_perror(char *str);

void	test(void);

#endif
