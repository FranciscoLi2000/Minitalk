/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:15:42 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 22:37:08 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_put_unsigned(unsigned int n)
{
	if (n >= 10)
		return (ft_put_unsigned(n / 10) + ft_putchar((n % 10) + '0'));
	else
		return (ft_putchar(n + '0'));
}

int	ft_put_hex(unsigned int n, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		return (ft_put_hex(n / 16, upper) + ft_putchar(base[n % 16]));
	else
		return (ft_putchar(base[n]));
}
