#include "minishell.h"

// static void	print_echo(char **lex, int option) -> doesn't work for "echo 'one    two'"...
// {
// 	int		index;
// 	int		sub_index;
// 	char	quote;

// 	quote = 0;
// 	index = option;
// 	while (lex[++index])
// 	{
// 		if (index > option + 1)
// 			write(1, " ", 1);
// 		sub_index = -1;
// 		while (lex[index][++sub_index])
// 		{
// 			if (ft_strchr("'\"", lex[index][sub_index]))
// 			{
// 				if (!quote)
// 					quote = lex[index][sub_index];
// 				else if (lex[index][sub_index] == quote)
// 					quote = 0;
// 				else
// 					write(1, &lex[index][sub_index], 1);
// 			}
// 			else
// 				write(1, &lex[index][sub_index], 1);
// 		}
// 	}
// }

static void	print_echo(char *str)
{
	int		index;
	char	quote;

	index = 0;
	quote = 0;
	while (str[++index])
	{
		if (ft_strchr("'\"", str[index]))
		{
			if (!quote)
				quote = str[index];
			else if (str[index] == quote)
				quote = 0;
			else
				write(1, &str[index], 1);
		}
		else if (quote || str[index] != ' ')
			write(1, &str[index], 1);
		else if (str[index - 1] != ' ')
			write(1, " ", 1);
	}
}

void	exec_echo(char **lex, char *args)
{
	int		option;

	if (ft_arraylen(lex) == 1)
		return (ft_putendl(""));
	option = (!ft_strncmp(lex[1], "-n", 3));
	if (option)
		args = ft_strchr(args, 'n') + 1;
	if (check_quotes(args))
		printf("Unclosed quotes detected, pls fix");
	else
		print_echo(args);
	if (!option)
		printf("\n");
}

void	exec_cd(char **lex)
{
	char	*msg;

	if (ft_arraylen(lex) > 2)
		printf("-bash: cd: too many arguments\n");
	else if (chdir(lex[1]) == -1)
	{
		msg = ft_strjoin("-bash: cd: ", lex[1]);
		perror(msg);
		free(msg);
	}
}

void	display_pwd(void)
{
	char	str[255];

	if (getcwd(str, sizeof(str)))
			printf("%s\n", str);
}
