/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:25:25 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 22:34:46 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_handle_format(char type, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_put_hex(unsigned int n, int upper);
int	ft_putptr(unsigned long ptr);
int	ft_putptr_hex(unsigned long n);

#endif
