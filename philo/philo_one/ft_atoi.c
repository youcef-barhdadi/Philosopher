/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:17:40 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/05 20:45:46 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long int	res;

	res = 0;
	if ((*str == '-'))
		return (-1);
	while (*str >= 48 && *str <= 57)
	{
		if (res > ((res * 10) + (*str - '0')))
			return (-1);
		else if (res > ((res * 10) + (*str - '0')))
			return (0);
		else
			res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > INT_MAX || *str != '\0')
		res = -1;
	return (res);
}
