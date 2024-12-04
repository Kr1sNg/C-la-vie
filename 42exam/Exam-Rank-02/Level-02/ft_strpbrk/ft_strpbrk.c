/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:07 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 18:26:55 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (ft_strchr(s2, *s1) == 1)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	const char *s1 = "Hello World, the function locates the first occurrence ";
	const char *s2 = "drunk";

	char *f;
	f = ft_strpbrk(s1, s2);
	printf("ft_strpbrk: %s\n", f);

	char *r = strpbrk(s1, s2);
	printf("strpbrk: %s\n", r);

	return (0);
}
*/
