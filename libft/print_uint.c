/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:27:57 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:37:04 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	num_len_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	num;
	unsigned int	len;
	char			*str;

	len = num_len_unsigned(n);
	num = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void	print_uint(t_print *tab)
{
	unsigned int	num;
	char			*str;

	num = va_arg(tab->args, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return ;
	tab->tl += write(1, str, ft_strlen(str));
	free(str);
}
