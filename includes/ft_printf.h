#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *fmt, ...);

/* dispatcher */
int	handle_format(char c, va_list ap);

/* char & string */
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	print_char(va_list ap);
int	print_str(va_list ap);

/* numbers */
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	print_unsigned(va_list ap);

/* hex & ptr */
int	ft_put_hex(unsigned long n, char *base);
int	print_hex(va_list ap, char c);
int	print_ptr(va_list ap);

#endif
