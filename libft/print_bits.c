/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:20:46 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:01:53 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1. Initialize a counter variable i to 8
2. Initialize a variable bit to 0
3. Loop through each bit of octet
4. Shift the bit of octet to the right i times and use the bitwise AND operator
with 1 to get the bit value.
5. Then add 48 to convert the bit value to its ASCII representation ('0' or '1')
6. Write the ASCII representation of the bit to the standard output (stdout)
*/

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}
