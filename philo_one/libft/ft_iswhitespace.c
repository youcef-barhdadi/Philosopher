/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:25:56 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/10/15 23:25:59 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}
