/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:43:00 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 00:07:44 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_convert(char *base, char c)
{
	int i = 0;
	if (c >= 'A' && c <= 'F')
		c = c + ('a' - 'A');
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char *base = "0123456789abcdef";
	int	nb = 0;
	int i = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		sign = -1;
		nb = -nb;
		i++;
	}
	while (str[i] != '\0')
	{
		nb = (nb * str_base) + ft_convert(base, str[i]);
		i++;
	}
	return (nb * sign);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_atoi_base("f23a6", 16));
}
*/
