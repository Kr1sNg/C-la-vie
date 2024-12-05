/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:04:43 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 09:29:11 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int nb = atoi(av[1]);
	if (ac != 2 || nb < 1)
		return (printf("\n"), -1);
	int i = 2;
	if (nb == 1)
		return (printf("1\n"), 0);
	while (i < nb)
	{
		if (nb % i != 0)
			i++;
		else
		{
			printf("%i*", i);
			nb = nb / i;
		}
	}
	printf("%i", i);
	printf("\n");
	return (0);
}
