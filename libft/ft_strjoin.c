/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:37:36 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 18:42:44 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static int	ft_strs_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

static char	*ft_strcpy_and_advance(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*tmp;
	int		i;

	if (size == 0)
		return (ft_strdup(""));
	joined = (char *)malloc(ft_strs_len(size, strs, sep) + 1);
	if (!joined)
		return (NULL);
	tmp = joined;
	i = 0;
	while (i < size)
	{
		tmp = ft_strcpy_and_advance(tmp, strs[i]);
		if (i++ < size - 1)
			tmp = ft_strcpy_and_advance(tmp, sep);
	}
	*tmp = '\0';
	return (joined);
}
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = malloc(len1 + len2 + 1);
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
