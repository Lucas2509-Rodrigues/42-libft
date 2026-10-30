/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:44:36 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/30 08:45:31 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = 0;
	len_src = ft_strlen(src);
	while (len_dst < n && dst[len_dst])
		len_dst++;
	if (n <= len_dst)
	{
		return (n + len_src);
	}
	while (src[i] && i < n && (len_dst + i + 1) < n)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*#include <stdio.h>
#include <string.h>
int main (void)
{
	size_t	n;
	char	dst[10] = "teste";
	n = 0;
	n = ft_strlcat(dst,"tete", 10);
	printf("%zu\n", n);
}*/