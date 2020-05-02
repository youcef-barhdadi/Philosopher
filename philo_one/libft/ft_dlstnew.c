/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:31:00 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/02/01 19:43:54 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(t_dlstelment *elemt)
{
	t_dlist *dlist;

	dlist = (t_dlist *)malloc(sizeof(t_dlist));
	if (!dlist)
		return (NULL);
	dlist->size = 0;
	dlist->head = elemt;
	dlist->tail = elemt;
	return (dlist);
}