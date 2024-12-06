/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:24:26 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 09:58:22 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), -1);
	
	unsigned char ascii[256] = {0};
	int i = 0;
	int j = 0;

	while (av[1][i] != '\0')
	{
		if (ascii[(unsigned char)av[1][i]] == 0)
		{
			write(1, &av[1][i], 1);
			ascii[(unsigned char)av[1][i]] = 1;
		}
		i++;
	}
	while (av[2][j] != '\0')
	{
		if (ascii[(unsigned char)av[2][j]] == 0)
		{
			write(1, &av[2][j], 1);
			ascii[(unsigned char)av[2][j]] = 1;
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
