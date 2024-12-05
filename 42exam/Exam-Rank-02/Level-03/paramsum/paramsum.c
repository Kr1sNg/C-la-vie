/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:45:33 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 18:58:45 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(unsigned int nb)
{
	unsigned long n = nb;
	char	c;
	
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}	

int	main (int ac, char ** av)
{
	if (av[1] == 0)
		return (write(1, "0\n", 2));
	unsigned int n = ac - 1;
	ft_putnbr(n);
	write(1, "\n", 1);
	return (0);
}
	
