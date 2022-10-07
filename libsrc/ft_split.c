#include "libft.h"

static size_t	count_words(char const *s, char c);
static void		*split_free(char **split);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;
	size_t	i;
	size_t 	len;
	
	word_count = count_words(s, c);
	split = (char **) malloc(sizeof (char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (word_count && *s == c)
			s++;
		len = ft_strchr(s, c) - s;
		split[i] = ft_substr(s, 0, len);
		if (!split[i])
			return (split_free(split));
		i++;
		s = s + len;
	}
	split[i] = NULL;
	return (split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	if (!s || !*s)
	{
		ft_printf("%d\n", word_count);
		return (0);
	}
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		if (*s == c || !*s)
		{
			word_count++;
			while (*s && *s == c)
				s++;
		}
	}
	ft_printf("%d\n", word_count);
	return (word_count);
}

static void	*split_free(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
