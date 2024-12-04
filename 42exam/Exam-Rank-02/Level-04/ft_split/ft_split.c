/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:37:38 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 10:56:41 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_word(char *str)
{
	int	i = 0;
	int count = 0;

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '	'))
			i++;
		if (str[i] != '\0' && (str[i] != ' ' && str[i] != '\n' && str[i] != '	'))
		{
			count++;
			while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\n' && str[i] != '	'))
				i++;
		}
	}
	return (count);
}

int count_char(char *str)
{
	int	i = 0;

	while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\n' && str[i] != '	'))
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	len = count_char(str);
	int	i = 0;
	char *arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *str)
{
	int i = 0;
	int	j = 0;
	int	len = count_word(str);
	char **arrs = malloc(sizeof(char *) * (len + 1));
	
	if (!arrs)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		if (str[i] != '\0' && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
		{
			arrs[j] = ft_strdup(&str[i]);
			j++;
			while (str[i] != '\0' && (str[i] != ' ' && str[i] != '	'&& str[i] != '\n'))
				i++;
		}
	}
	arrs[j] = '\0';
	return (arrs);
}

/*
#include <stdio.h>

int	main(void)
{
	char *str = "  Hom nay\n la thu   tu 8 words   \n	. ";
	char **arrs = ft_split(str);

	int	i = 0;
	while (i < count_word(str))
	{
		printf("arr[%i]: %s\n", i, arrs[i]);
		free(arrs[i]);
		i++;
	}
	free(arrs);
	return (0);
}
*/

