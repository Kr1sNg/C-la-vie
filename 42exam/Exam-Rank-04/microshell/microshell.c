#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	err_mes(char *mes)
{
	int	i = 0;
	while (mes[i])
		write(2, &mes[i++], 1);
	return (1);
}

int	ft_cd(char **av, int i)
{
	if (i != 2)
		return (err_mes("error: cd: bad arguments\n"));
	else if (chdir (av[i]) == -1) // because cd is av[0]
		return (err_mes("error: cd: cannot change directory to "),
				err_mes(av[i]),
				err_mes("\n"));
	return (0);
}

int ft_execute(char **av, char **env, int i)
{
	int	fd[2];
	int	status;
	int	is_pipe = (av[i] && strcmp(av[i], "|") == 0);

	// if it's the pipeline, but can't create pipe:
	if (is_pipe && pipe(fd) == -1)
		return (err_mes("error: fatal\n"));
	
	int	pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (err_mes("error: fatal\n"));
		execve(av[0], av, env); // (path, argv, env)
		return (err_mes("error: cannot execute "), 
				err_mes(av[0]),
				err_mes("\n"));
	}

	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (err_mes("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	int status = 0;

	if (ac > 1)
	{
		while (*av && *(av + 1))
		{
			av++;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if (strcmp(*av, "cd") == 0)
				status = ft_cd(av, i);
			else if (i)
				status = ft_execute(av, env, i);
			av += i;
		}
	}
}




