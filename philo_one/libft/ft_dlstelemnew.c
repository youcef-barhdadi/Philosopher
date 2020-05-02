/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstelemnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:39:25 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/02/01 14:42:33 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlstelment	*ft_dlstelemnew(void *data)
{
	t_dlstelment *elem;

	elem = (t_dlstelment *)malloc(sizeof(t_dlstelment));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	elem->prv = NULL;
	return (elem);
}