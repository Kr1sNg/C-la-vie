#include <unistd.h> //read, write
#include <stdlib.h> // malloc

#ifndef BUFFER_SIZE 42
# define BUFFER_SIZE 42
#endif

char    *ft_read_file(int fd, char *remain);
char    *ft_line(char *buffer);
char    *ft_remain(char *buffer);
char	*ft_lineappend(char *remain, char *buffer);


char	*ft_read_file(int fd, char *remain)
{
	char 	*buffer;
	int		byte_read;

	if (!remain)
	{
		remain = ft_calloc(1, sizeof(char));
		if (!remain)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //TODO
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		remain = ft_lineappend(remain, buffer); //TODO
		if (!ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (remain);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	// malloc to eol (1 for \n, 1 for \0 !?)
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' & buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_remain(char *buffer)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	remain = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!remain)
		return (NULL);
	i += (buffer[i] == '\n');
	j = 0;
	while (buffer[i] != '\0')
		remain[j++] = buffer[i++];
	remain[j] = '\0';
	free(buffer);
	return (remain);
}

char *ft_lineappend(char *remain, char *buffer)
{
	char *new_remain;

	new_remain = ft_strjoin(remain, buffer);
	free(remain);
	return (new_remain);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) //check if fd and BZ is valid
		return (NULL);
//call read_file to fill up the buffer with data from file
	buffer = ft_read_file(fd, buffer); //TODO
	if (!buffer)
		return (NULL);
//extract the next line (if any) from the buffer with ft_line
	line = ft_line(buffer); //TODO
// update buffer by removing the line we just read, and remain is the rest(after\n - if any)
	buffer = ft_remain(buffer); //TODO
	return (line);
}

