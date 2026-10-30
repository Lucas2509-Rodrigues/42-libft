/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 11:32:55 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/30 08:28:55 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	if (ptr < ptr2)
	{
		while (n > 0)
		{
			*ptr++ = *ptr2++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			ptr[n - 1] = ptr2[n - 1];
			n--;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int main (void)
{
	char buff[] = "abcdef";
	char buff2[] = "abcdef";
	ft_memmove(buff + 1, buff, 0);
	memmove(buff + 1, buff, 0);
	printf("ft_memmove = %s\n",buff);
	printf("memmove = %s\n",buff2);
}*/