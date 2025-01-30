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

char	*ft_strchr(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}


char	*ft_calloc(size_t mem, size_t size)
{
	char *s;
	size_t i = 0;

	s = malloc(mem * size);
	if (!s)
		return (NULL);
	while (i < mem * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char 	*new;
	int 	i = 0;
	int 	j = 0;

	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	return (new);
}

// join oldbuffer and temp to become a new buffer then free old buffer
char	*ft_join_and_free(char *buffer, char *temp)
{
	char *new_buf;

	new_buf = ft_strjoin(buffer, temp);
	free(buffer);
	return (new_buf);
}


char	*ft_read_line(int fd, char *buffer)
{
	char	*temp;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);

	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(temp);
			return (NULL);
		}
		buffer
}


char	*ft_line(char *buffer);
char	*ft_remain(char buffer);



char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

//only BUFFER_SIZE need to check == 0 or not
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);

	line = ft_line(buffer);

	buffer = ft_remain(buffer);

	return (line);
}
