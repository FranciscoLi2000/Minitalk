/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:17:31 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 02:26:21 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	len;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start < end)
			tab[i] = end--;
		else
			tab[i] = start--;
		i++;
	}
	return (tab);
}
