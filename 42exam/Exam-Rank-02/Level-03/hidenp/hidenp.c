/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:31:11 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 12:39:10 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), -1);

	int	i = 0;
	int j = 0;
	int len = ft_strlen(av[1]);

	while (av[2][j] != '\0' && av[1][i] != '\0')
	{
		if (av[1][i] == av[2][j])
			i++;
		j++;
	}
	if (i == len)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
	
