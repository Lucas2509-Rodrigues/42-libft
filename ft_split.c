/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:21:45 by lucas             #+#    #+#             */
/*   Updated: 2026/10/23 14:25:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	start;
	int	c_words;

	c_words = 0;
	start = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			start = 0;
		if (s[i] != c && start == 0)
		{
			c_words++;
			start = 1;
		}
		i++;
	}
	return (c_words);
}

static int	count_letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*dup_word(char const *src, char c)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (count_letters(src, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**free_all(char **str, int j)
{
	while (j >= 0)
		free(str[j--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			str[j] = dup_word(&s[i], c);
			if (!str[j])
				return (free_all(str, j - 1));
			j++;
			i += count_letters(&s[i], c);
		}
	}
	return (str);
}
