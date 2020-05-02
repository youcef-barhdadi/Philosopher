/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:30:05 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/20 02:24:00 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *a;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		a = ft_lstlast(*alst);
		a->next = new;
	}
}
