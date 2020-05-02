/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:43:21 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/02/01 19:44:33 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void   ft_dlstpush(t_dlist *lst, t_dlstelment *elem)
{
    if (!lst)
        return ;        
    if (!lst->head)
    {
        lst->head = elem;
        lst->tail = elem;   
    }
    lst->tail->next = elem;
    elem->prv = lst->tail;
    lst->tail =elem;
    lst->size++;
}