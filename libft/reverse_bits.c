/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:26:28 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:00:58 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
res << 1: 
Move all bits in res one place to the left
Example: if res = 00000010, then res << 1 = 00000100

octet & 1:
Get the least significant bit (LSB) of octet
& 1 masks all bits except the last one

If octet = 00000101, then octet & 1 = 00000001

res = (res << 1) | (octet & 1)

You insert the current LSB of octet into the right side of res

It's like "rebuilding the number in reverse"

octet = octet >> 1: Move all bits in octet one place to the right

So next time, you'll get the next bit to the left

*/

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	res = 0;
	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}
