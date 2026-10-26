/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 11:32:55 by marvin            #+#    #+#             */
/*   Updated: 2026/09/04 11:32:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	if (ptr < ptr2)
	{
		while (i < n)
		{
			ptr[i] = ptr2[i];
			i++;
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
