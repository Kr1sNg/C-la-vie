/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:02:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/05 19:27:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(int start, int end)
{
	int len = 0;

	if (start < end)
		len = (end - start + 1);
	else
		len = (start - end + 1);
	return (len);
}

int	*ft_rrange(int start, int end)
{
	int len = ft_len(start, end);
	int	*arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);

	int i = 0;
	while (i < len)
	{
		arr[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return (arr);
}

/*
#include <stdio.h>

int	main(void)
{
	int start = 0;
	int end = -3;

	int len = ft_len(start, end);
	int	*arr = ft_rrange(start, end);
	
	int i = 0;
	while (i < len)
	{
		printf("%i, ", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/	
