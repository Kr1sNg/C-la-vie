/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:02:03 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 10:19:05 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int	i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), -1);
	int i = 0;
	int j = 0;
	int len = ft_strlen(av[1]);

	while (av[2][j] != '\0' && av[1][i] != '\0')
	{
		if (av[1][i] == av[2][j])
			i++;
		j++;
	}
	if (i == len)
		ft_putstr(av[1]);
	write(1, "\n", 1);
}
