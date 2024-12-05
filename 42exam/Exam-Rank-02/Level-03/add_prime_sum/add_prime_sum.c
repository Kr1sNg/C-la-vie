/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 18:13:21 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	nb = 0;
	int i = 0;
	int sign = 1;

	if (s[i] == '-')
	{
		nb = -nb;
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	ft_putnbr(int nb)
{
	long	n = nb;
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	add_prime_sum(int nb)
{
	int i = 2;
	int total = 0;

	if (nb == 1)
		total = 1;
	while (nb >= i)
	{
		if (ft_is_prime(i) == 1)
			total += i;
		i++;
	}
	return (total);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "0\n", 2), -1);
	int nb = ft_atoi(av[1]);
	if (nb <= 0)
		return (write(1, "0\n", 2), -1);
	int total = add_prime_sum(nb);
	ft_putnbr(total);
	write(1, "\n", 1);
}
