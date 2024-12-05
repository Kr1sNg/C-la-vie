/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:48:51 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 20:05:07 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int nb = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	long n = nb;
	char c;

	if (nb > 9)
		ft_putnbr(n / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), -1);
	int	nb = ft_atoi(av[1]);
	int i = 1;
	int re;
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		re = i * nb;
		ft_putnbr(re);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
