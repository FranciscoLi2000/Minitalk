/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:08:37 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:35:57 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	num_len_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char	*digits;
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = num_len_base(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	len--;
	while (n > 0)
	{
		str[len] = digits[n % base];
		n /= base;
		len--;
	}
	return (str);
}

void	print_hex(t_print *tab, int uppercase)
{
	unsigned int	num;
	char			*str;

	num = va_arg(tab->args, unsigned int);
	str = ft_itoa_base(num, 16, uppercase);
	if (!str)
		return ;
	tab->tl += write(1, str, ft_strlen(str));
	free(str);
}
