/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:35:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/05/26 22:10:50 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	errm(char *mess)
{
	while (*mess)
		write(2, mess++, 1);
	return (1);
}

int	ft_cd(char **av, int i)
{
	if (i != 2)
		return (errm("error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1)
		return (errm("error: cd: cannot change directory to "), errm(av[1]), errm("\n"));
	return (0);
}

int	ft_execute(char **av, char **env, int i)
{
	int		status;
	int 	fd[2];
	int 	is_pipe = (av[i] && (strcmp(av[i], "|") == 0));
	pid_t 	pid = fork();

	if ((is_pipe && pipe(fd) == -1) || (pid == -1))
		return (errm("error: fatal\n"));
	if (pid == 0) // in child
	{
		av[i] = NULL; //erase "|"
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (errm("error: fatal\n"));
		execve(av[0], av, env);
		return (errm("error: cannot execute "), errm(av[0]), errm("\n"));
	}
	// in parent
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (errm("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	int	status = 0;
	
	if (ac > 1)
	{
		while (*av && *(av + 1))
		{
			av++;
			while (av[i] && (strcmp(av[i], "|") != 0) && (strcmp(av[i], ";") != 0)) // not equal
				i++;
			if (strcmp(av[0], "cd") == 0)
				status = ft_cd(av, i);
			else if (i)
				status = ft_execute(av, env, i);
			av += i;
		}
	}
	return (status);
}
