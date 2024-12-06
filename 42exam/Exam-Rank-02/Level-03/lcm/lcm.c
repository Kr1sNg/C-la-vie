/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:46:00 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/06 12:53:49 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	hcf;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		hcf = (a / 2) + 1;
	else
		hcf = (b / 2) + 1;

	while (a % hcf != 0 || b % hcf != 0)
		hcf--;

	return (a * b / hcf);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", lcm(6, 8));
}
*/
