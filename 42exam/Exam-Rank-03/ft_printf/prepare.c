#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	char *d;
	int 	i = 0;

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
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

#include <stdarg.h>

int ft_prints(char *s)
{
	int i = 0;

	if (!s)
		return (ft_prints("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_printd(long nb)
{
	char c;
	int count = 0;

	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_printd(nb / 10);
		count += ft_printd(nb % 10);
	}
	else
	{
		c = nb + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int ft_printx(unsigned long long nb)
{
	int count = 0;
	char *s = "0123456789abcdef";

	if (nb > 15)
	{
		count += ft_printx(nb / 16);
		count += ft_printx(nb % 16);
	}
	else
		count += write(1, &s[nb], 1);
	return (count);
}

int ft_printf(const char *mand, ...)
{
	va_list ap;
	int i = 0;
	int count = 0;

	va_start(ap, mand);
	while (mand[i])
	{
		if (mand[i] == '%')
		{
			i++;
			if (mand[i] == 's')
				count += ft_prints(va_arg(ap, char *));
			else if (mand[i] == 'd')
				count += ft_printd((long)va_arg(ap, int));
			else if (mand[i] == 'x')
				count += ft_printx((unsigned long long)va_arg(ap, unsigned int));
		}
		else
			count += write(1, &mand[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

#include <fcntl.h>

int main(void)
{
	int i = 0;
	char *line;
	int fd;

	fd = open("README.md", O_RDONLY);
	if (fd == -1)
		return (-42);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("line [%d - %x]: %s", i, i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
