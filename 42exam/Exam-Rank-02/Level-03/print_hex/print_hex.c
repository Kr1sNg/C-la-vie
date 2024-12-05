/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:28:42 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 19:40:06 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int	nb = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_puthex(int nb)
{
	long n = nb;
	char *base = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), -1);
	int nb = ft_atoi(av[1]);
	ft_puthex(nb);
	write(1, "\n", 1);
	return (0);
}	
		
