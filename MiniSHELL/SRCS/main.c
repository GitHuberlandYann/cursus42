/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:26:08 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/06 15:10:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setup(void)
{
	printf("\033[0;32m*\t\t\t---\t\t\t*\n");
	printf("\n");
	printf("|\t\t     minishell     \t\t|\n");
	printf("\n");
	printf("*\t\t\t---\t\t\t*\033[0m\n");
}

static void	loop(void)
{
	char	*rl;

	while (1)
	{
		rl = readline("$> ");
		add_history(rl);
		if (rl && !ft_strncmp(rl, "exit", 4) && (!rl[4] || rl[4] == ' '))
			exit(EXIT_SUCCESS);
		free(rl);
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	setup();
	loop();
	return (0);
}
