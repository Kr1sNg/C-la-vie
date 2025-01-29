#include <unistd.h> //write
#include <stdarg.h>	//std arguments

int	ft_print_str(char *s)
{
	int i = 0;

	if (!s)
		return (ft_print_str("null"));

	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_print_dec(long nb)
{
	char	c;
	int		count = 0;

	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_print_dec(nb / 10);
		count += ft_print_dec(nb % 10);
	}
	else
	{
		c = nb + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int ft_print_hex(unsigned long long nb)
{
	int		count = 0;
	char	*s = "0123456789abcdef";

	if (nb > 15)
	{
		count += ft_print_hex(nb / 16);
		count += ft_print_hex(nb % 16);
	}
	else
		count += write(1, &s[nb], 1);
	return (count);
}

int     ft_print_format(char c, va_list ap)
{
    int count = 0;

    if (c == 's')
        count += ft_print_str(va_arg(ap, char *)); //va_arg: get the next arg (consider as a string)
    else if (c == 'd')
        count += ft_print_dec((long)va_arg(ap, int));
    else if (c == 'x')
        count += ft_print_hex((unsigned long long)va_arg(ap, unsigned int));
    return (count);
}

int ft_printf(const char *mandarg, ...)
{
    int     i = 0;
    int     count = 0;
    va_list ap; //arg pointer

    va_start(ap, mandarg); // point to the first va arg mandarg
    while (mandarg[i])
    {
        if (mandarg[i] == '%')
        {
            i++;
            count += ft_print_format(mandarg[i], ap);
        }
        else
            count += write(1, &mandarg[i], 1);
        i++;
    }
    va_end(ap);
    return (count);
}

int	main(void)
{
	int i;
	i = ft_printf("%s\n", ""); //5
	ft_printf("length of printf: %d\n", i);
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
