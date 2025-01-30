/*
char    *ft_read_file(int fd, char *buffer); => return new_buffer
char    *ft_line(char *buffer); => return line
char    *ft_remain(char *buffer);
char    *ft_lineappend(char *buffer, char *temp); use to make remain
*/

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


void	*ft_calloc(size_t mem, size_t size)
{
	size_t i = 0;
	char *loc;

	loc = malloc(mem * size);
	if (!loc)
		return (NULL);
	while (i < mem * size)
	{
		loc[i] = 0;
		i++;
	}
	return (loc);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *new;

	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i++] = s2[j];
	return (new);
}

//append buffer and temp
char    *ft_lineappend(char *buffer, char *temp)
{
	char *new_buffer;

	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	return (new_buffer);
}

char	*ft_read_file(int fd, char *buffer)
{
	char 	*temp;
	int		byte_read;

	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	byte_read = 1;
	//read until the eof or the '\n'
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(temp);
			return (NULL);
		}
		//temp[byte_read] = '\0'; // k can vi da calloc
		buffer = ft_lineappend(buffer, temp); //new buffer is created
		if (ft_strchr(temp, '\n') != NULL)
			break;
	}
	free(temp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char 	*line;
	int		i;
	
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\n'; //line[i + 1] is already calloced by '\0' to termine the line!
	return (line);
}

char	*ft_remain(char *buffer)
{
	int	i;
	int j;
	char *remain;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0') //it means this is eof and the line is already read and taken by ft_line 
	{
		free(buffer);
		return (NULL);
	}
	//if not, it means we still have next line to read
	remain = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!remain)
		return (NULL);
	i++; // i += (buffer[i] == '\n'), but after check '\0', buffer[i] is definetly == '\n'
	j = 0;
	while (buffer[i])
		remain[j++] = buffer[i++];
	//remain[j] = '\0'; //donot need thanks to calloc
	free(buffer);
	return (remain);
}
	

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer); //add the old buffer into and continue (or start) to read until get \n or eof
	if (!buffer)
		return (NULL);
	line = ft_line(buffer); // return line
	buffer = ft_remain(buffer); // the rest of buffer (after removing the whole line), which will be arg of read_fine in next call of gnl. 
	return (line);
}


#include <stdio.h>
#include <fcntl.h>

int main(void)
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
	close(fd);
	return (0);
}
