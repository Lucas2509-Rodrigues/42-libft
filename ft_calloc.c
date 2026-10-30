/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:38:06 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/23 14:34:05 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(	size_t nmemb, size_t size)
{
	char	*str;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (size * nmemb));
	return (str);
}
