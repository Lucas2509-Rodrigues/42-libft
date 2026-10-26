/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:57 by lucas             #+#    #+#             */
/*   Updated: 2026/10/26 12:28:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*head;
	void		*p;
	t_list		*new_l;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		p = f(lst->content);
		new_l = ft_lstnew(p);
		if (!new_l)
		{
			del(p);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_l);
		lst = lst->next;
	}
	return (head);
}
