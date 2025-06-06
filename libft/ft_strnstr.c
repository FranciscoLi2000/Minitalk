/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:40:31 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 02:01:00 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match_len(char *s1, char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i] || i >= len)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (is_match_len(&str[i], to_find, len - i))
			return (&str[i]);
		i++;
	}
	return (0);
}
