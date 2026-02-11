/* utils.c - Utility functions for minitalk */
/* Author: your_login */
/* Description: Basic string and I/O utility functions */

#include "minitalk.h"

/**
 * ft_putstr - Write a string to stdout
 * @str: String to write
 */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * ft_putchar - Write a character to stdout
 * @c: Character to write
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * ft_putnbr - Write an integer to stdout
 * @n: Integer to write
 */
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar('0' + n);
}

/**
 * ft_strlen - Calculate the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

/**
 * char_to_bits - Convert a character to 8 bits (LSB first)
 * @c: Character to convert
 * @bits: Array to store the bits (8 elements, bits[0] = LSB)
 *
 * This function converts a character to its binary representation
 * and stores each bit in the provided array, LSB first.
 */
void	char_to_bits(char c, int *bits)
{
	int	i;

	for (i = 0; i < 8; i++)
	{
		bits[i] = c & (1 << i);
		if (bits[i])
			bits[i] = 1;
	}
}

/**
 * bit_to_char - Convert 8 bits to a character (LSB first)
 * @bits: Array containing 8 bits (bits[0] = LSB, bits[7] = MSB)
 *
 * Return: The character represented by these bits
 */
char	bit_to_char(int *bits)
{
	char	c;
	int	i;

	c = 0;
	for (i = 0; i < 8; i++)
	{
		if (bits[i])
			c |= (1 << i); /* LSB first: bit i goes to position i */
	}
	return (c);
}