/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:04:54 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/01/31 12:54:06 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strequ(const char *s1, const char *s2)
{
    int l1;
    int l2;

    l1 = ft_strlen(s1);
    l2 = ft_strlen(s2);
    if (l1 < l2)
        return !ft_strncmp(s1, s2, l2);
    return !ft_strncmp(s1, s2, l1);
}