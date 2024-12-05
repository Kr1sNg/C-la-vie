/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:53:08 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 15:31:04 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (printf("\n"), -1);
	
	int a = atoi(av[1]);
	int b = atoi(av[3]);
	int r;

	if (av[2][0] == '+')
		r = a + b;
	else if (av[2][0] == '-')
		r = a - b;
	else if (av[2][0] == '*')
		r = a * b;
	else if (av[2][0] == '/')
		r = a / b;
	else if (av[2][0] == '%')
		r = a % b;
	else
		return (printf("\n"), -1);
	printf("%i\n", r);
	return (0);
}
