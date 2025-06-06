/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:46:42 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 02:54:23 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	g;

	if (a > b)
		g = a;
	else
		g = b;
	while (1)
	{
		if ((g % a == 0) && (g % b == 0))
			return (g);
		g++;
	}
}
