#include <unistd.h>
#include <stdarg.h>

int ft_print_str(char *s);
int ft_print_dec(long nb);
int ft_print_hex(unsigned long long nb);

int	ft_printf(const char *mandarg, ...)
{
	int		i = 0;
	int		count = 0;
	va_list	ap;

	va_start(ap, mandarg);
	while (mandarg[i])
	{
		if (mandarg[i] == '%')
		{
			i = i + 1;
			if (mandarg[i] == 's')
				count += ft_print_str(va_arg(ap, char *));
			else if (mandarg[i] == 'd')
				count += ft_print_dec((long)va_arg(ap, int));
			else if (mandarg[i] == 'x')
				count += ft_print_hex((unsigned long long)va_arg(ap, unsigned int));
		}
		else
			count += write(1, &mandarg[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_str(char *s)
{
	int	i = 0;

	if (!s)
		return (ft_print_str("(null)"));

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_dec(long nb)
{
	int	count = 0;
	char c;

	if (nb < 0)
	{
		count +=  write(1, "-", 1);
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

int	ft_print_hex(unsigned long long nb)
{
	int count = 0;
	char *s = "0123456789abcdef";

	if (nb > 15)
	{
		count += ft_print_hex(nb / 16);
		count += ft_print_hex(nb % 16);
	}
	else
	{
		count += write(1, &s[nb], 1);
	}
	return (count);
}	



/*
#include <stdio.h>
int main(void)
{
	int a = 0;
	int b = 0;
	printf("printf: %s\n", "");
	ft_printf("ft_printf: %s\n", NULL);
	printf("printf: %d\n", -2147483647);
	ft_printf("this is: %d\n", -2147483648);
	a = printf("   hex: %x\n", 42);
	b = ft_printf("ft_hex: %x\n", 42);
	ft_printf("a = %d, b = %d\n", a, b); 
}
*/

