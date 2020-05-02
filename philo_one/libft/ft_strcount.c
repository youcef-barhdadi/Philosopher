/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:00:45 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/01/31 14:07:08 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcount(const char *s1, char c)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
			count++;
		i++;
	}
	return (count);
}
