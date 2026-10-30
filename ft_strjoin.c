/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 10:13:01 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/30 08:51:38 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int main(void)
{
	char *str;
	str = ft_strjoin("teste", "teste");
	printf("%s\n", str);
	free(str);
}*/