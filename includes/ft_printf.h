/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:02:49 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 23:35:30 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		tl;
	char	spec;
}	t_print;

char	*ft_utoa(unsigned int n);
char	*ft_itoa_base(unsigned long long n, int base, int uppercase);
char	*ft_ptoa(void *ptr);
void	ft_parse_specifier(t_print *tab, char spec);
void	print_char(t_print *tab);
void	print_str(t_print *tab);
void	print_int(t_print *tab);
void	print_uint(t_print *tab);
void	print_hex(t_print *tab, int uppercase);
void	print_ptr(t_print *tab);
int		ft_printf(const char *format, ...);

#endif
