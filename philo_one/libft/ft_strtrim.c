/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:23:59 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/20 02:07:43 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trimed;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = 0;
	len = ft_strlen(s);
	while (ft_strchr(set, s[start]))
		start++;
	while (ft_strchr(set, s[len]))
	{
		len--;
		end++;
	}
	if (start >= (int)ft_strlen(s))
	{
		trimed = (char *)malloc(sizeof(char));
		trimed[0] = '\0';
		return (trimed);
	}
	trimed = ft_substr(s, start, ft_strlen(s) - (start + end) + 1);
	return (trimed);
}
