/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 18:30:57 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	ft_free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int	ft_fill_split(char **res, const char *s, char c)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[end])
	{
		if (s[end] == c)
			start = end + 1;
		else if (s[end + 1] == '\0' || s[end + 1] == c)
		{
			res[i] = ft_substr(s, start, end - start + 1);
			if (!res[i])
				return (ft_free_all(res, i - 1), 0);
			i++;
		}
		end++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int			count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!ft_fill_split(res, s, c))
		return (NULL);
	return (res);
}