/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:25:25 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 15:18:25 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), -1);
	
	int len = ft_strlen(av[1]);
	while (len > 0)
	{
		while (len > 0 && av[1][len - 1] != '\t' && av[1][len - 1] != ' ')
		{		
			len--;
		}
		ft_putstr(&av[1][len]);
		while (len > 0 && (av[1][len - 1] == '\t' || av[1][len - 1] == ' '))
		{
			write(1, " ", 1);
			len--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
