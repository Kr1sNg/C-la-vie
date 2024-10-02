/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_camel_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:14:07 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/10/02 21:27:38 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.
Examples

"the-stealth-warrior" gets converted to "theStealthWarrior"

"The_Stealth_Warrior" gets converted to "TheStealthWarrior"

"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
*/

char ft_majus(char c)
{
  if (c >= 'a' && c <= 'z')
    c = c - ('a' - 'A');
  return (c);
}

void to_camel_case(const char *text, char *camel)
{
	int i = 0;
	int j = 0;
	while (text[i] != '\0')
	{
    	if (text[i] == '-' || text[i] == '_')
    	{
        	i = i + 1;
        	camel[j] = ft_majus(text[i]);
    	}
		else
    		camel[j] = text[i];    
    	j++;
    	i++;
  	}
	camel[j] = '\0';
}

#include<stdio.h>
int	main(void)
{
	char str[50] = "The_Stealth_Warrior";
	char camel[50];
	to_camel_case(str, camel);
	printf("%s\n", camel);
}
