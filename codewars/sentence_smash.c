/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_smash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:35:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/10/02 21:38:45 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a function that takes an array of words and smashes them together into a sentence and returns the sentence. You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word. Be careful, there shouldn't be a space at the beginning or the end of the sentence!
Example

['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
*/

#include <stdlib.h>

int ft_strlen(const char *const str)
{
	int  i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strcat(char *dest, const char *const src)
{
	int i = 0;
   	int len = ft_strlen(dest);
   	while (src[i] != '\0')
     	{
        	dest[len + i] = src[i];
        	i++;
      	}
    dest[len + i] = '\0';
    return (dest);
}

int ft_count(const char *const words[], size_t count)
{
  	unsigned int i = 0;
  	unsigned int len = 0;
  	while (i < count)
    {
      	len = len + ft_strlen(words[i]);
      	if (i < count - 1)
        len++;
      	i++;
    }
  	return (len + 1);
}

char *smash (const char *const words[/* count */], size_t count)
{
  	unsigned int i = 0;
  	unsigned int len = ft_count(words, count);
  	char *final;
  	final = malloc(sizeof(char) * len);
  	if (!final)
    	return (NULL);
  	final[0] = '\0';
  	while (i < count)
    {
      	final = ft_strcat(final, words[i]);
      	if (i < count - 1)
        	final = ft_strcat(final, " ");
      	i++;    
  	}
  	return (final);
}
