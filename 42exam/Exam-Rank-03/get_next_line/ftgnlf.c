#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s);

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
		if (buffer[pos - 1] == '\n' || i >= 69999)
			break;
		}
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
