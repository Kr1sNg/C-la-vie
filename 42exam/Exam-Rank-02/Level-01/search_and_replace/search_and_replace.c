/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:17:54 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 14:33:04 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_para_check(char *s)
{
	if (!s || s[1])
		return (0);
	if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 4 || ft_para_check(argv[2]) == 0 || ft_para_check(argv[3]) == 0)
		return (write(1, "\n", 1), -1);
	
	int i = 0;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == argv[2][0])
		{
			write(1, &argv[3][0], 1);
			i++;
		}
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
