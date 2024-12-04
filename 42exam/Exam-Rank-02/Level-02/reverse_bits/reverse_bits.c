/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:27:34 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 22:26:46 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
unsigned char	reversed_bits(unsigned char octet)
{
	unsigned char rev = 0;
	int	i = 0;

	while (i < 8)
	{
		rev = (rev << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (rev);
}
*/

unsigned char	reversed_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	unsigned char c = 122; // 0111 1010

	c = reversed_bits(c); // 0101 1110 (94)
	printf("%i\n", c);
}
*/
