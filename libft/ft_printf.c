#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
			len += handle_format(fmt[++i], ap);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
