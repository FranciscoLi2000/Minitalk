/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:25:00 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:36:50 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	tab->tl += write(1, str, ft_strlen(str));
}
