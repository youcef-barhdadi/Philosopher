/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:47:25 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/18 22:06:57 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void *ret;

	ret = dst;
	if (dst == src)
	{
		return (dst);
	}
	else if (src < dst && dst < src + n)
	{
		dst += n;
		src += n;
		while (n--)
			*(unsigned char *)(--dst) = *(unsigned char *)(--src);
		return (ret);
	}
	else
	{
		while (n--)
			*(unsigned char *)(dst++) = *(unsigned char *)(src++);
		return (ret);
	}
}
