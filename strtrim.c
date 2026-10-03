/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 10:38:19 by lucas             #+#    #+#             */
/*   Updated: 2026/09/21 11:26:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;
	unsigned int	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, ft_strlen(s) + 1);
	start = 0;
	j = 0;
	end = ft_strlen(s);
	while (s[start] && (s[start] == ' ' || s[start] == '\n'
			|| s[start] == '\t'))
		start++;
	while (end > start && (s[end - 1] == ' '
			|| s[end - 1] == '\n' || s[end - 1] == '\t'))
		end--;
	while (start < end)
		str[j++] = s[start++];
	return (str);
}
