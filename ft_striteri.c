/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:26:59 by lurodri2          #+#    #+#             */
/*   Updated: 2026/09/14 11:47:39 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	if (f)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
