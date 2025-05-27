#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	errm(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	return (1);
}

int ft_cd(char *path, int i)
{
	if (i != 2)
		return (errm("error: cd: bad arguments\n"));
	else if (chdir(path) == -1)
		return (errm("error: cd: cannot change directory to "), errm(path), errm("\n"));
	return (0);
}

int	ft_execute(char **av, char **env, int i)
{
	int	is_pipe, fd[2], pid, status;

	is_pipe = av[i] && (strcmp(av[i], "|") == 0);
	if (is_pipe && pipe(fd) == -1)
		return (errm("error: fatal\n"));
	
	pid = fork();
	if (pid == -1)
		return (errm("error: fatal\n"));
	if (pid == 0)
	{
		av[i] = NULL;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (errm("error: fatal\n"));
		execve(av[0], av, env);
		return (errm("error: cannot execute "), errm(av[0]), errm("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
		return (errm("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int status = 0;

	if (ac > 1)
	{
		while (*av && *(av + 1))
		{
			av++;
			i = 0;
			while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
				i++;
			if (strcmp(av[0], "cd") == 0)
				status = ft_cd(av[1], i);
			else if (i)
				status = ft_execute(av, env, i);
			av += i;
		}
	}
	return (status);
}




