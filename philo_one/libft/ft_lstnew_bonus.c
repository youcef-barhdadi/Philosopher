/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:50:22 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/19 16:37:27 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *a;

	a = (t_list *)malloc(sizeof(t_list));
	if (a != NULL)
	{
		a->content = content;
		a->next = NULL;
	}
	return (a);
}
