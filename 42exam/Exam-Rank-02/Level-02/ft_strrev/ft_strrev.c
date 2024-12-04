/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:28:17 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 18:42:51 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strrev(char *str)
{
	int i = 0;
	int	len = ft_strlen(str);
	char c;

	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[(len - 1) - i];
		str[(len - 1) - i] = c;
		i++;
	}
	return (str);
}

/*
//Have to test with s[], can't use *s in this situation!
#include <stdio.h>
int	main(void)
{
	char s[] = "Hello World!";

	printf("Before: %s\n", s);
	ft_strrev(s);
	printf("After : %s\n", s);
}
*/
