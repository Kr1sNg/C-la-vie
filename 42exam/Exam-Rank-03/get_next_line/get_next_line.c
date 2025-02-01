#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int	i = 0;
	char *d;

	while (s[i])
		i++;
	d = malloc(i + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}


/*
1- init 5 variables with 3 static
2- check error fd, SZ, read
3- loop to read char until a \n or eof
	3.1- refill buffer by read
	3.2- copy char from buffer to line
	3.3- break on \n or buffer overflow
4- make sure line termine with '\0'
5- check if there's data read
6- return (strdup(line));
*/

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int	rd;
	static int	pos;
	size_t		i = 0;
	char		line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	while (1)
	{
		if (pos >= rd)
		{
			pos = 0;
			rd = read(fd, buffer, BUFFER_SIZE);
			if (rd <= 0)
				break;
		}
		line[i++] = buffer[pos++];
		if (buffer[pos - 1] == '\n' || i >= sizeof(line) - 1)
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int i = 1;
	char *line;

	fd = open("README.md", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line[%i]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}



