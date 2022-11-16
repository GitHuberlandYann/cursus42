#include "pipex.h"

void	ft_pipe(int	pipefd[2])
{
	int	pipe_ret;

	pipe_ret = pipe(pipefd);
	if (pipe_ret == -1)
		ft_perror("pipe");
}

void	ft_fork(int	*child_pid)
{
	*child_pid = fork();
	if (*child_pid == -1)
		ft_perror("fork");
}

void	ft_wait_child(t_parent p)
{
	p.c_wait = waitpid(p.c_pid, &p.w_status, WUNTRACED | WCONTINUED);
	while (!WIFEXITED(p.c_wait) && !WIFSIGNALED(p.c_wait))
	{
		p.c_wait = waitpid(p.c_pid, &p.w_status, WUNTRACED | WCONTINUED);
		if (p.c_wait == -1)
			ft_perror("waitpid");
		if (WIFEXITED(p.w_status))
			printf("exited, status=%d\n", WEXITSTATUS(p.w_status));
		else if (WIFSIGNALED(p.w_status))
			printf("killed by signal %d\n", WTERMSIG(p.w_status));
		else if (WIFSTOPPED(p.w_status))
			printf("stopped by signal %d\n", WSTOPSIG(p.w_status));
		else if (WIFCONTINUED(p.w_status))
			printf("continued\n");
	}
}