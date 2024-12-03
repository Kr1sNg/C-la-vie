/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:12:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 20:20:00 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j = 0;
	int temp;

	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}

/*
#include <stdio.h>

void ft_print_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	while (i < size)
	{
		printf("%i, ", tab[i]);
		i++;
	}
}

int	main(void)
{
	int tab[] = {45, 971, -21, -145, -741, 254, 2, 31212, -54, 123, 66, 0};
	printf("Before: ");
	ft_print_tab(tab, 12);
	sort_int_tab(tab, 12);
	printf("\nAfter: ");
	ft_print_tab(tab, 12);
	printf("\n");
}
*/	
