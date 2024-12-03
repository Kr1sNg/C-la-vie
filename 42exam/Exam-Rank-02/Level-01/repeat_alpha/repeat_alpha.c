/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:33:13 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 11:14:19 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printchar(int c)
{
	int i = 'a';
	if (c >= 'a' && c <= 'z')
	{
		while (i < c)
		{
			write(1, &c, 1);
			i++;
		}
	}
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc != 2)
		return (write(1, "\n", 1), -1);
	while (argv[1][i] != '\0')
	{
		ft_printchar(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
