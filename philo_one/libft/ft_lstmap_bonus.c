/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:24:40 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/18 18:54:05 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *node;
	t_list *a;

	if (!lst || !f)
		return (NULL);
	node = ft_lstnew((f)(lst->content));
	a = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew((f)(lst->content));
		if (!node->next)
		{
			ft_lstclear(&a, del);
			return (NULL);
		}
		lst = lst->next;
		node = node->next;
	}
	return (a);
}
