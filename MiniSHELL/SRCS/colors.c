#include "minishell.h"

/* any call to this function must be followed by a printf("\n"); */
void	set_col(char *col)
{
	printf("%s", col);
}

void	greet_user(void)
{
	printf("*\t\t\t---\t\t\t*\n");
	printf("\n");
	printf("|\t\t     minishell     \t\t|\n");
	printf("\n");
	printf("*\t\t\t---\t\t\t*");
}

void	close_program(void)
{
	printf("\n");
	set_col(RED);
	greet_user();
	set_col(WHITE);
	printf("\n");
	exit(EXIT_SUCCESS);
}
