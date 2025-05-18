/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:04:25 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:36:31 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(void *ptr)
{
	unsigned long long	addr;
	char				*hex;
	char				*result;

	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_strdup("(nil)"));
	hex = ft_itoa_base(addr, 16, 0);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}

void	print_ptr(t_print *tab)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(tab->args, void *);
	if (!ptr)
	{
		tab->tl += write(1, "(nil)", 5);
		return ;
	}
	str = ft_ptoa(ptr);
	tab->tl += write(1, str, ft_strlen(str));
	free(str);
}
