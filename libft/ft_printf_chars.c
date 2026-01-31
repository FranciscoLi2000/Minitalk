#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (ft_putchar(c));
}

int	print_str(va_list ap)
{
	return (ft_putstr(va_arg(ap, char *)));
}

int	handle_format(char c, va_list ap)
{
	if (c == 'c')
		return (print_char(ap));
	else if (c == 's')
		return (print_str(ap));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (print_unsigned(ap));
	else if (c == 'x' || c == 'X')
		return (print_hex(ap, c));
	else if (c == 'p')
		return (print_ptr(ap));
	return (0);
}
