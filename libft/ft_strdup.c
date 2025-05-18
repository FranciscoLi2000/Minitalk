/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:25:33 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 20:53:49 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;
	int		size;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (s == 0)
		return (0);
	size = len + 1;
	dst = malloc(size * sizeof(char));
	if (dst == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
