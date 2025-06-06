/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:04:29 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:09:30 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(int c, int base_len)
{
	char	*base_1;
	char	*base_2;
	int		i;

	base_1 = "0123456789abcdef";
	base_2 = "0123456789ABCDEF";
	i = 0;
	while (i < base_len)
	{
		if (c == base_1[i] || c == base_2[i])
			return (1);
		i++;
	}
	return (0);
}

static int	convert_base(const char *str, int base, int i)
{
	int	result;

	result = 0;
	while (str[i] && is_valid(str[i], base))
	{
		result *= base;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		i++;
	}
	return (result);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (convert_base(str, str_base, i) * sign);
}
