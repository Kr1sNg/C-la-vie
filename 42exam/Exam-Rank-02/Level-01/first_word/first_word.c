/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:28:25 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/01 22:49:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;
	
	if (argc != 2)
		return (write(1, "\n", 1), -1);
	while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '	'))
		i++;
	if (argv[1][i] != '\0' && (argv[1][i] != ' ' && argv[1][i] != '	'))
	{
		while (argv[1][i] != '\0' && (argv[1][i] != ' ' && argv[1][i] != '	'))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	return (write(1, "\n", 1), 0);
}
