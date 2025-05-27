/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:17:03 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/05/27 11:23:15 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
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
	int	is_pipe, fd[2], pid, status;

	//1- check is_pipe
	is_pipe = av[i] && (strcmp(av[i], "|") == 0);
	//2- if there's "|", create pipe
	if (is_pipe && pipe(fd) == -1)
		return (errm("error: fatal\n"));
	//3-create fork
	pid = fork();
	if (pid == -1)
		return (errm("error: fatal\n"));
	//4-in child process
	if (pid == 0)
	{
		//4a-delete "|" or ";"
		av[i] = NULL;
		//4b-try to set pipe to write (even if there's no pipe)
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (errm("error: fatal\n"));
		//4c-execute
		execve(*av, av, env);
		//4d-if can't execute it will happen:
		return (errm("error: cannot execute "), errm(av[0]), errm("\n"));
	}
	//5-in main, waitpid
	waitpid(pid, &status, 0);
	//6-try to read from child
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
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if (strcmp(*av, "cd") == 0)
				status = ft_cd(av, i);
			else if (i)
				status = ft_execute(av, env, i);
			av += i;
		}
	}
	return (status);
}


