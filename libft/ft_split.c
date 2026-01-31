#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == sep);
}

static size_t	count_words(char const *s, char sep)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_sep(*s, sep) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_sep(*s, sep))
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	start;
	size_t	word;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			res[word] = ft_substr(s, start, i - start);
			if (!res[word])
			{
				free_all(res, word);
				return (NULL);
			}
			word++;
		}
		else
			i++;
	}
	res[word] = NULL;
	return (res);
}
