/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:42:08 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 20:10:55 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	long	n = nbr;
	char	c;
	
	if (n < 0)
	{
		write( 1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	i = 1;

	while (i < 101)
	{
		if (i % 3 == 0)
			write(1, "fizz", 5);
		if (i % 5 == 0)
			write(1, "buzz", 5);
		if (i % 5 != 0 && i % 3 != 0)
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

