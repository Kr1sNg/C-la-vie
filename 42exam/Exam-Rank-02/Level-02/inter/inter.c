/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:22:00 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 10:30:20 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_inside(char *s, char c, int index)
{
	int	i = 0;

	while (s[i] != '\0' && i < index)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcher(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), -1);

	int	i = 0;

	while (av[1][i] != '\0')
	{
		if (ft_strcher(av[2], av[1][i]) == 1 && ft_check_inside(av[1], av[1][i], i) == 0)
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}	
