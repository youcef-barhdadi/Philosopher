/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:27 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/19 22:15:12 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char cc;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (unsigned char *)src;
	cc = (unsigned char)c;
	while (n--)
	{
		*(d++) = *(s);
		if (*s++ == cc)
			return (d);
	}
	return (0);
}
