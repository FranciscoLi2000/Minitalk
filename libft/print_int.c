/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:26:27 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:36:09 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_print *tab)
{
	char	*str;
	int		num;

	num = va_arg(tab->args, int);
	str = ft_itoa(num);
	if (!str)
		return ;
	tab->tl += write(1, str, ft_strlen(str));
	free(str);
}
