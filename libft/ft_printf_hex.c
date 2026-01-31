#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hex(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	print_hex(va_list ap, char c)
{
	if (c == 'x')
		return (ft_put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	return (ft_put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}

int	print_ptr(va_list ap)
{
	unsigned long	p;

	p = (unsigned long)va_arg(ap, void *);
	if (!p)
		return (ft_putstr("0x0"));
	return (ft_putstr("0x") + ft_put_hex(p, "0123456789abcdef"));
}
