/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:33:27 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 21:46:46 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//use (byte & (1 << i)) (or 0000 i000)  to check if this ith bit is '0' or '1'

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	while (i >= 0)
	{
		if ((octet & (1 << i)) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

/*
int	main(void)
{
	print_bits(2);
}
*/
