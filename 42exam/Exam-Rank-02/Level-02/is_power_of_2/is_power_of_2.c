/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:23 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 21:07:04 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 != 0)
			return (0);
		n /= 2;
	}
	return (1);
}
*/

// using bitwise: because power of 2 always have only one bit '1'
int is_power_of_2(unsigned int n)
{
	return (n > 0 && (n & (n - 1)) == 0); //return 1 for true
}

/*
#include <stdio.h>
int	main(void)
{
	printf("0 is not, 1 is power: %i\n", is_power_of_2(9));
}
*/
