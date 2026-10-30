/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:14:36 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/26 14:08:46 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = p;
	}
}
