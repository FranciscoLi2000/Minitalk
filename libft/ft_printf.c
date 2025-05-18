/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:48:53 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:35:00 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_specifier(t_print *tab, char spec)
{
	if (spec == 'c')
		print_char(tab);
	else if (spec == 's')
		print_str(tab);
	else if (spec == 'p')
		print_ptr(tab);
	else if (spec == 'd' || spec == 'i')
		print_int(tab);
	else if (spec == 'u')
		print_uint(tab);
	else if (spec == 'x')
		print_hex(tab, 0);
	else if (spec == 'X')
		print_hex(tab, 1);
	else if (spec == '%')
		tab->tl += write(1, "%", 1);
	else
	{
		tab->tl += write(1, "%", 1);
		tab->tl += write(1, &spec, 1);
	}
}

int	ft_printf(const char *format, ...)
{
	t_print	tab;
	int		i;

	va_start(tab.args, format);
	tab.tl = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			ft_parse_specifier(&tab, format[i]);
		}
		else
			tab.tl += write(1, &format[i], 1);
		i++;
	}
	va_end(tab.args);
	return (tab.tl);
}
