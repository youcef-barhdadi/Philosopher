/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:22:02 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/10 16:18:05 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_phili *phili)
{
	long	stamp;

	pthread_mutex_lock(&phili->global->display);
	stamp = get_time() - phili->global->start;
	printf("%ld  philopshper %d %s\n", stamp / 1000, phili->number, str);
	pthread_mutex_unlock(&phili->global->display);
}

void	mysleep(long target)
{
	long	start;

	start = get_time();
	while (get_time() - start < target)
		usleep(100);
}

void	*start_phili(void *a)
{
	t_phili	*phili;

	phili = (t_phili *)a;
	if (phili->number % 2 == 0)
		mysleep(50);
	phili->last_meal = get_time();
	while (phili->global->die == 0)
	{
		ft_message("THINKING", phili);
		eat(phili);
		if (phili->eat == phili->global->how)
		{
			pthread_mutex_lock(&phili->global->eat_mutex);
			phili->global->eaten += 1;
			pthread_mutex_unlock(&phili->global->eat_mutex);
			phili->done = 1;
			break ;
		}
		ft_message("SLEEPING", phili);
		mysleep(phili->global->to_sleep);
	}
	phili->global->alive--;
	return (NULL);
}
