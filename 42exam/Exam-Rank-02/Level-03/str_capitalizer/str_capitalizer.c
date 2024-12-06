/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:11:26 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 13:30:23 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	ft_capi(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

char	ft_minus(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}

void ft_printcap(char *s)
{
	int i = 1;

	s[0] = ft_capi(s[0]);
	write(1, &s[0], 1);
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i - 1]) == 1)
			s[i] = ft_capi(s[i]);
		else
			s[i] = ft_minus(s[i]);
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1), -1);

	int i = 1;
	
	while (i < ac)
	{
		ft_printcap(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
	
