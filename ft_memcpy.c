/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:44:48 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/29 17:34:18 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int main (void)
{
	char buff[] = "abcdef";
	char buff2[] = "abcdef";
	ft_memcpy(buff + 1, buff, 0);
	memcpy(buff + 1, buff, 0);
	printf("ft_memcpy = %s\n",buff);
	printf("memcpy = %s\n",buff2);
}*/