/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:58:09 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/04 12:26:18 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puts(char *s)
{
	int	i = 0;

	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
	{	
		write(1, &s[i], 1);
		i++;
	}
}

void	last_word(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t'))
		len--;
	while (len > 0 && (s[len - 1] != ' ' && s[len -1] != '\t'))
		len--;
	ft_puts(&s[len]);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (write(1, "\n", 1), -1);
	last_word(argv[1]);
	write(1, "\n", 1);
}
