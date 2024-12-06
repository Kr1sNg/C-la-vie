/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:55:30 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 13:07:24 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* positive greatest common divisor */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (printf("\n"), -1);

	int a = atoi(av[1]);
	int b = atoi(av[2]);
	int h;

	if (a <= 0 || b <= 0)
		return (printf("\n"), -1);

	if (a > b)
		h = (a / 2) + 1;
	else
		h = (b / 2) + 1;

	while ((a % h != 0) || (b % h != 0))
		h--;
	printf("%i\n", h);
}
