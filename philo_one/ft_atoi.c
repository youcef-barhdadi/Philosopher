/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:17:40 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/06/06 07:20:14 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_atoi(char const *s)
{
	long			nbr;
	long			sign;
	int				i;
	unsigned long long	lon;

	lon = 9223372036854775807;
	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_iswhitespace((int)s[i]) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
		{
			sign = -1;
			nbr = -nbr;
		}
	while (ft_isdigit(s[i]) && s[i])
	{
		if ((unsigned long)nbr > lon / 10 ||
			((unsigned long)nbr == lon / 10 && ((unsigned long)nbr % 10) > 7))
			return (sign > 0 ? -1 : 0);
		nbr = nbr * 10 + (s[i++] - 48);
	}
	return (nbr * sign);
}
