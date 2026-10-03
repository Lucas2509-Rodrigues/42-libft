/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:43:50 by lucas             #+#    #+#             */
/*   Updated: 2026/09/16 12:05:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	result;

	if (!s1 || !s2)
		return (0);
	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	return (0);
}
