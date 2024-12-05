/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:13:43 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 20:10:10 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strchr(const char *s, int c)
{
	size_t	i = 0;

	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i = 0;
	
	while (s[i] != '\0' && ft_strchr(reject, s[i]) == 0)
		i++;
	return (i);
}

/*
int	main(void)
{
	char *s = "The strspn() function calculates the length (in bytes) of the initial segment of s which consists entirely of bytes in accept.";
	char *rj = "abc";

	int	a = ft_strcspn(s, rj);
	printf("ft_strcspn: %i\n", a);

	int	b = strcspn(s, rj);
	printf("strcspn: %i\n", b);

}
*/	
