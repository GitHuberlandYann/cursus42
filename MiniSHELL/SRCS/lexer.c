#include "minishell.h"

void	lexer(char *rl)
{
	char	**lex;

	if (!rl[0])
		return ;
	lex = ft_split(rl, ' ');
	if (!ft_strncmp(lex[0], "test", 5))
		test();
	else if (!ft_strncmp(lex[0], "echo", 5))
		exec_echo(lex, &rl[4]);
	else if (!ft_strncmp(lex[0], "cd", 3))
		exec_cd(lex);
	else if (!ft_strncmp(lex[0], "pwd", 4))
		display_pwd();
	else if (!ft_strncmp(lex[0], "export", 7))
		printf("export : TODO\n");
	else if (!ft_strncmp(lex[0], "unset", 6))
		printf("unset : TODO\n");
	else if (!ft_strncmp(lex[0], "env", 4))
		printf("env : TODO\n");
	else if (!ft_strncmp(lex[0], "exit", 5))
		close_program();
		
	ft_free_arr(lex);
}

/* I put this here for now */
int	check_quotes(char *str)
{
	int		index;
	int		quote;

	index = -1;
	while (str[++index])
	{
		if (ft_strchr("'\"", str[index]))
		{
			quote = str[index];
			++index;
			while (str[index] && str[index] != quote)
				++index;
			if (!str[index])
				return (1);
		}
	}
	return (0);
}
