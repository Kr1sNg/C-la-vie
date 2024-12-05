/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:07 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 16:11:53 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1), -1);
	
	int len = ft_strlen(av[1]);
	int i = 0;
	int first;
	while (i < len && (av[1][i] == ' ' || av[1][i] == '\t'))
		i++;
	first = i;
	while (i < len && (av[1][i] != ' ' && av[1][i] != '\t'))
		i++;
	while (i < len)
	{
		while (i < len && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		if (i < len && (av[1][i] != ' ' && av[1][i] != '\t'))
		{
			ft_putstr(&av[1][i]);
			write(1, " ", 1);
			while (i < len && (av[1][i] != ' ' && av[1][i] != '\t'))
				i++;
		}
	}
	ft_putstr(&av[1][first]);
	write(1, "\n", 1);
	return (0);
}
