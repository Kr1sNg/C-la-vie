#include <unistd.h>
#include <stdarg.h>

int	ft_print_str(char *s);
int	ft_print_dec(long nb);
int	ft_print_hex(unsigned long long nb);

int	ft_printf(const char *mand, ...)
{
	int	i = 0;
	int count = 0;
	va_list ap;

	va_start(ap, mand);
	while (mand[i])
	{
		if (mand[i] == '%')
		{
			i++;
			if (mand[i] == 's')
				count += ft_print_str(va_arg(ap, char *));
			else if (mand[i] == 'd')
				count += ft_print_dec((long)va_arg(ap, int));
			else if (mand[i] == 'x')
				count += ft_print_hex((unsigned long long)va_arg(ap, unsigned int));
		}
		else
			count += write(1, &mand[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_str(char *s)
{
	int i = 0;
	int count = 0;

	if (!s)
		return ft_print_str("(null)");
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	ft_print_dec(long nb)
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
	char *s = "0123456789abcdef";
	int	count = 0;

	if (nb > 15)
	{
		count += ft_print_hex(nb / 16);
		count += ft_print_hex(nb % 16);
	}
	else
		count += write(1, &s[nb], 1);
	return (count);
}

int main(void)
{
	ft_printf("%s\n", "This is a string");
	ft_printf("%s\n", NULL);
	ft_printf("%s: dec %d = hex %x\n", "Exchange", 420, 420);
}





