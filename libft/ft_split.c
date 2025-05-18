/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/01/02 18:44:28 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c);

static char	**allocate_substrings(char const *s, char c, int *count)
{
	char	**result;
	int		i;

	*count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			(*count)++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	result = malloc((*count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

static int	get_wordlen(const char *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	return (len);
}

static int	store_substrings(char const *s, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[j] = ft_substr(s, i, get_wordlen(s, c, i));
			if (!result[j])
				return (j);
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	result[j] = NULL;
	return (-1);
}

static void	free_split_memory(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		failed_index;
	int		count;

	result = allocate_substrings(s, c, &count);
	if (!s || !result)
		return (NULL);
	failed_index = store_substrings(s, c, result);
	if (failed_index != -1)
	{
		free_split_memory(result, failed_index - 1);
		return (NULL);
	}
	return (result);
}
