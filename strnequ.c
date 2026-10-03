/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:07:00 by lucas             #+#    #+#             */
/*   Updated: 2026/09/16 12:10:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	result;

	if (!s1 || !s2)
		return (0);
	result = ft_strncmp(s1, s2, n);
	if (result == 0)
		return (1);
	return (0);
}
