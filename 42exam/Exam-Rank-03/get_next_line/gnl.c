#include <unistd.h> //read, write
#include <stdlib.h> // malloc

#define BUFFER_SIZE 42

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
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
		remain = ft_lineappend(remain, buffer);
		if (ft

	



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
