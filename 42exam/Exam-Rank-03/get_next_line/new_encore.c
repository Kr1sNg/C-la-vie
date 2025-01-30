#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int 	i = 0;
	char	*new;

	while (s[i])
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	//1 - init 5 variables with 3 statics
	char		line[70000];
	static char buffer[BUFFER_SIZE];
	static int	rd; // nb of byte read
	static int	pos; //position cursor of buffer
	size_t		i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 ,0) < 0)
		return (NULL);
	//loop to read character until a \n or eof
	while (1)
	{
		//refill the buffer 
		if (pos >= rd) //means that it pass the read chars, need to reset
		{
			pos = 0;
			rd = read(fd, buffer, BUFFER_SIZE);
			if (rd <= 0)
				break;
		}
		// copy char from buffer to line
		line[i++] = buffer[pos++];
		// break on \n or buffer overflow
		if (buffer[pos - 1] == '\n' || (i >= (sizeof(line) - 1))) //max i = 69999
			break;
	}
	line[i] = '\0';
	//i == 0 means no data to read
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int i = 1;
	int	fd;
	char *line;

	fd = open("README.md", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line[%i]: %s", i, line);
		free(line);
		i++;
	}
	close (fd);
	return (0);
}