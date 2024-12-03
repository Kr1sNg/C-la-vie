/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:20:33 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/03 09:30:34 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int main(void)
{
	int a = 2;
	int b = 3;
	printf("Before: a: %i, b: %i\n", a, b);
	ft_swap(&a, &b);
	printf("After: a: %i, b: %i\n", a, b);
}

