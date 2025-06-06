/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:20:17 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 18:44:01 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int i = 0;

	while (s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), -1);
	int i = 0;
	while (av[1][i] != '\0' && (av[1][i] == '\t' || av[1][i] == ' '))
		i++;
	if (av[1][i] != '\0' && (av[1][i] != '\t' && av[1][i] != ' '))
	{
		ft_putstr(&av[1][i]);
		while (av[1][i] != '\0' && (av[1][i] != '\t' && av[1][i] != ' '))
			i++;
	}
	while (av[1][i] != '\0')
	{
		while (av[1][i] != '\0' && (av[1][i] == '\t' || av[1][i] == ' '))
			i++;
		if (av[1][i] != '\0' && (av[1][i] != '\t' && av[1][i] != ' '))
		{
			write(1, "   ", 3);
			ft_putstr(&av[1][i]);
			while (av[1][i] != '\0' && (av[1][i] != '\t' && av[1][i] != ' '))
				i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
