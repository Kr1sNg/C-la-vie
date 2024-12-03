/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:21:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 11:43:49 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*s1 = "\201";
	char	*s2 = "A";
	printf("ft_strcmp: %i\n", ft_strcmp(s1, s2));
	printf("strcmp: %i\n", strcmp(s1, s2));
}
