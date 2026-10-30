/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurodri2 <lurodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:57 by lurodri2          #+#    #+#             */
/*   Updated: 2026/10/29 11:04:27 by lurodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*helper(t_list	**head, void (*del)(void *), void	*p)
{
	if (p)
		del(p);
	ft_lstclear(head, del);
	return (NULL);
}

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
		if (!p)
			return (helper(&head, del, p));
		new_l = ft_lstnew(p);
		if (!new_l)
			return (helper(&head, del, p));
		ft_lstadd_back(&head, new_l);
		lst = lst->next;
	}
	return (head);
}
