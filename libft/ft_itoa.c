#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	nb;

	nb = n;
	len = ft_numlen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (len-- > 0 && res[len] != '-')
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
