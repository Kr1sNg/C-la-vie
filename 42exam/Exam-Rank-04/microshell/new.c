/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:17:03 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/05/27 09:28:29 by tat-nguy         ###   ########.fr       */
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

int	ft_cd(char **av, int i);
int	ft_execute(char **av, char **env, int i);

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	int	status = 0;
	
	if (ac > 1)
	{
		while (*av, *(av + 1))
		{
			av++;
			while (av[i] && av[])
		}
	}
}


