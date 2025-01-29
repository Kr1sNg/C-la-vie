#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i, j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	char		read_buffer[BUFFER_SIZE + 1];
	int			byte_read, i, len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (!ft_strchr(buffer, '\n') && (byte_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
	{
		read_buffer[byte_read] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
	}
	if (!buffer[0])
		return (free(buffer), buffer = NULL, NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	len = i + 1;
	if (buffer[i] == '\n')
		len++;
	line = ft_calloc(len, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	tmp = buffer + i;
	buffer = ft_calloc(ft_strlen(tmp) + 1, sizeof(char));
	if (buffer)
	{
		int j = 0;
		while (tmp[j])
		{
			buffer[j] = tmp[j];
			j++;
		}
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *line;
	int	i = 1;
	int	fd;

	fd = open("new.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line [%i]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
