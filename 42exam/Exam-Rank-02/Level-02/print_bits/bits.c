/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:29:41 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 21:22:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	main(void)
{
	int a = 5; // 0x0000 0101
	printf("a = %i\n", a);

	// set the second bit from 0 to 1 as 0x0000 0111 (= 7)
	a |= (1 << 1);
	printf("set: a = %i\n", a);

	// clear the second bit from 1 to 0
	a &= ~(1 << 1);
	printf("clear: a = %i\n", a);

	// toggle the first bit from 1 to 0 as 0x0000 0100 (=4)
	a ^= (1 << 0);
	printf ("toggle: a = %i\n", a);

	// check if the second bit is 0 or 1 as 0x0000 01?0
	if ((a & (1 << 2)) != 0)
		printf("1\n");
	else
		printf("0\n");
	
	int b = 33; //0x0010 0001;
	b = b >> 2; //0x0000 1000; = 8
	printf("33 >> 2: %i\n", b);
}
