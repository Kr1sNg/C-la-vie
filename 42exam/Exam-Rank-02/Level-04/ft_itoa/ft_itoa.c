/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:42:06 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 14:01:09 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_numlen(long n)
{
	int i = 1;

	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_recursive(long n, char *str, int *i)
{
	if (n > 9)
		ft_recursive(n / 10, str, i);
	str[*i] = n % 10 + '0';
	(*i)++;
} 

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int i = 0;
	int len = ft_numlen(n);
	char *str = malloc(sizeof(char) * (len + 1));
	
	if (!str)
		return (NULL);	
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	ft_recursive(n, str, &i);
	str[i] = '\0';
	return (str);
}


#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int n = INT_MAX;
	int len = ft_numlen(n);
	char *str = ft_itoa(n);
	printf("len: %i,\nn: %s\n", len, str);
	free(str);
	return (0);
}
