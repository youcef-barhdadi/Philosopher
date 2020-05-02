/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:54:04 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/18 21:04:45 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t i;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
	{
		return (size + len_src);
	}
	else
		len_src = len_dst + len_src;
	while (src[i] != '\0' && len_dst < size - 1)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (len_src);
}
