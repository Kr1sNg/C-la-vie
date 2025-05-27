/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:25:27 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/05/27 11:29:33 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	error_message(char *message)
{
	while (*message)
		write(2, message++, 1);
	return (1);
}

int	cd(char **av, int i)
{
	if (i != 2)
		return (error_message("error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1)
		return (error_message("error: cd: cannot change directory to "),
				error_message(av[1]),
				error_message("\n"));
	return (0);
}
	
int	ft_execute(char **av, char **env, int i)
{
	int	fd[2];
	int	status;
	int	is_pipe = (av[i] && strcmp(av[i], "|") == 0); //=> give 0 or 1
	// - if there's no av -> false && false -> 0
	// - if there's av = ; -> true && false -> 0
	// true && true -> 1

	// execve will creates new process and totally replaces main process 
	// then executes and closes all when finishing, so all the following codes won't be executed if execve works 
	// so idea is create fork inside child process to run execve,
	// => when it terminates it doesn't matter to the main process
	
	if (is_pipe && pipe(fd) == -1)
		return (error_message("error: fatal\n"));
	
	int pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		if (is_pipe && (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (error_message("error: fatal\n"));
		execve(av[0], av, env); // (now it's already av + i)
		return (error_message("error: cannot execute "),
				error_message(av[0]),
				error_message("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error_message("error: fatal\n"));
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
			av++; // av = &av[i + 1] // move the pointer of *av
			i = 0;
			while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
				i++;
			if (strcmp(av[0], "cd") == 0) //because the pointer's moved already
				status = cd(av, i);
			else if (i != 0)
				status = ft_execute(av, env, i);
			av += i;
		}
	}
	return (status);
}

/* --test--
- /bin/echo hello
- /bin/echo hello ";" /bin/echo world
- /bin/echo hello ";" /bin/echo world ";"
- /bin/echo hello world "|" /usr/bin/tr a-z A-Z
- /bin/echo "one two three" "|" /usr/bin/tr ' ' '\n' "|" /usr/bin/grep two
- /bin/echo "first line" ";" /bin/echo "a b c" "|" /usr/bin/tr a-z A-Z
- /bin/echo "first line" ";" /bin/echo a b c ";" /bin/echo this is new line "|" /usr/bin/tr a-z A-Z
- /bin/echo "first line" ";" /bin/echo a b c ";" /bin/echo "this is new line" "|" /usr/bin/tr a-z A-Z 
- cd .. ";" /bin/pwd
- cd
- cd /invalid/path
- /not/a/real/command
- /bin/echo first line ";" /bin/echo a b c ";" /bin/echo this is new line "|" /usr/bin/tr a-z A-Z ";" cd .. "|" /bin/pwd
	first line
	a b c
	THIS IS NEW LINE
	/home/tat-nguy/42perso/C-la-vie/42exam/Exam-Rank-04

*/