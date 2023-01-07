/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:26:08 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/07 17:54:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* SIGINT = CTRL+C, */
static void	setup(void)
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_handler;
	if (sigaction(SIGINT, &act, NULL) == -1)
		ft_perror("sigaction");
	set_col(GREEN);
	greet_user();
	set_col(WHITE);
	printf("\n");
}

static void	loop(void)
{
	char	*rl;

	while (1)
	{
		rl = readline("$> ");
		if (!rl)	// == ctrl+D
			close_program();
		add_history(rl);
		lexer(rl);
		free(rl);
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	if (ac == 1)
	{
		setup();
		loop();
	}
	else
	{
		printf("I identify as a argument-less executable, please refer to me as such.\n");
		return (1);
	}
	return (0);
}
