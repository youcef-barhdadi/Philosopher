/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:28:00 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/07 15:36:16 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "philo.h"

void	free_all(t_phili **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->global->number)
	{
		pthread_mutex_destroy(&philo[i]->mutex);
		pthread_mutex_destroy(&philo[i]->global->display);
		free((*philo) + i);
		i++;
	}
	free(philo);
	exit(0);
}

void	eat(t_phili *phili)
{
	pthread_mutex_lock(&phili->mutex);
	pthread_mutex_lock(&phili->next->mutex);
	phili->eating = 1;
	ft_message("TAKE A FORK", phili);
	ft_message("TAKE A FORK", phili);
	ft_message("EATING", phili);
	phili->eat++;
	phili->last_meal = get_time();
	mysleep(phili->global->to_eat);
	pthread_mutex_unlock(&phili->next->mutex);
	pthread_mutex_unlock(&phili->mutex);
	phili->eating = 0;
}

long	get_time(void)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL))
		return (0);
	return (1000000 * start.tv_sec + start.tv_usec);
}

void	create_thread(t_global *global, t_phili **list, int i)
{
	int		re;

	list[i] = malloc(sizeof(t_phili));
	re = pthread_mutex_init(&list[i]->mutex, NULL);
	if (re != 0)
	{
		perror("error ");
		exit(1);
	}
	list[i]->number = i + 1;
	list[i]->last_meal = get_time();
	list[i]->global = global;
	if (i != 0)
	{
		list[i - 1]->next = list[i];
		list[i]->perv = list[i - 1];
	}
}

t_phili	**create_list(t_global *global)
{
	int		i ;
	int		ret;
	t_phili	**list ;

	i = 0;
	list = malloc(global->number * sizeof(t_phili **));
	while (i < global->number)
	{
		create_thread(global, list, i);
		i++;
	}
	list[0]->perv = list[global->number - 1];
	list[0]->done = 0;
	list[global->number - 1]->next = list[0];
	ret = pthread_mutex_init(&list[0]->global->display, NULL);
	ret = pthread_mutex_init(&list[0]->global->eat_mutex, NULL);
	if (ret != 0 )
	{
		perror("error ");
		free_all(list);
	}
	list[global->number - 1]->next = list[0];
	list[global->number - 1]->last = 1;
	return (list);
}
