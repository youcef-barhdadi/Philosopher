/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:45:34 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/12/20 04:47:48 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long get_time()
{
	struct timeval start;
	if (gettimeofday(&start, NULL))
		return (0);
	return (start.tv_sec *1000  + start.tv_usec / 1000 );

}

t_phili **create_list(t_global *g)
{

	t_phili **phili; 
	int i = 0;

	int number = g->number;
	phili = malloc(sizeof (t_phili *) * number);
	memset(phili,0, sizeof(t_phili *) * number);
	while(i < g->number)
	{
		phili[i] = malloc(sizeof(t_phili));
		memset(phili[i], 0,sizeof(t_phili));
		pthread_mutex_init(&phili[i]->take, NULL);
		pthread_mutex_init(&phili[i]->meal, NULL);
		phili[i]->number = i + 1;
		if (i != 0)
		{
			phili[i-1]->next = phili[i];
			phili[i]->perv = phili[i-1];
		}
		phili[i]->global =  g;
		phili[i]->last_meal = get_time();
		i++;
	}
	phili[0]->perv = phili[number-1];
	pthread_mutex_init(&phili[0]->global->mutex, NULL);
	phili[number - 1]->next = phili[0];
	phili[number -1]->last = 1;
	return phili;
}

void display(char *str, int n)
{
	write(1,str, ft_strlen(str));
	ft_putnbr_fd(n, 1);
	ft_putstr_fd("\n", 1);

}


void ft_message(char *str, t_phili *phili)
{
	char *number;
	long stamp;
	pthread_mutex_lock(&phili->global->display);
	stamp =  get_time()  - phili->global->start;
	number = ft_lltoa(stamp);
	ft_putstr_fd(number, 1);
	free(number);
	ft_putstr_fd(" philpspher ", 1);
	ft_putnbr_fd(phili->number, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	pthread_mutex_unlock(&phili->global->display);

}
void *start_phili(void *a)
{
	t_phili *phili = (void *)a;
	while (1)
	{
		ft_message("THINGKING", phili);
		pthread_mutex_lock(&phili->mutex);
		pthread_mutex_lock(&phili->perv->mutex);
		ft_message("TAKE A FORK", phili);
		ft_message("TAKE A FORK", phili);
		ft_message("EATING", phili);
		phili->eat ++;
		pthread_mutex_lock(&phili->meal);
		phili->last_meal = get_time();
		pthread_mutex_unlock(&phili->meal);
		usleep(phili->global->to_eat);
		pthread_mutex_unlock(&phili->mutex);
		pthread_mutex_unlock(&phili->perv->mutex);
		ft_message("SLEEPING", phili);
		usleep(phili->global->to_sleep);
	if (phili->global->time && phili->eat ==  phili->global->how)
			break ;

	}
	pthread_mutex_lock(&phili->global->mutex);
	phili->global->number--;
	pthread_mutex_unlock(&phili->global->mutex);
	return NULL;
}


void*	check(void *data)
{

	t_phili *phili;

	phili = (t_phili *)data;

	while (phili->global->dead == 0  && phili->global->number != 0)
	{
		pthread_mutex_lock(&phili->meal);
		long time = get_time() - phili->last_meal;
		if ( time > phili->global->to_die)
		{
			pthread_mutex_lock(&(phili->global->alive_mutex));
			phili->global->dead = 1;
			ft_message("DEAED", phili);
			pthread_mutex_unlock(&(phili->global->alive_mutex));

			pthread_mutex_unlock(&phili->meal);
			return 0;
		}
		pthread_mutex_unlock(&phili->meal);
	}
	// printf("hi\n");
	return 0;
}


void start_thread(t_phili **thread, int number)
{	
	int i = 0;
	while (i < number)
	{
		int num = pthread_create(&thread[i]->tid, NULL, start_phili, (void *)thread[i]);
		int n =  pthread_create(&thread[i]->check, NULL, check, (void *)thread[i]);

		if (num != 0 || n != 0)
		{
			perror("thead :");
			exit(1);
		}

		i++;
	}


}



void	parse_args(int argc, char **argv, t_global *global)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat time_to_sleap [number_of_times_each_philospher_must_eat]\n", 1);
		exit(1);
	}
	global->number = ft_atoi(argv[1]);
	global->to_die = ft_atoi(argv[2]) ;

	global->to_eat = ft_atoi(argv[3]) * 1000;
	global->to_sleep = ft_atoi(argv[4]) *1000;
	global->start = get_time();
	if (argc == 6)
	{
		global->time = 1;
		global->how = ft_atoi(argv[5]);
	}

}

int main(int argc, char **argv)
{
	t_global global;

	pthread_mutex_init(&global.mutex, NULL);
	pthread_mutex_init(&global.display, NULL);
		pthread_mutex_init(&global.alive_mutex, NULL);
	parse_args(argc, argv, &global);
	t_phili **p = create_list(&global);
	int i = 0;

	global.dead = 0;
	start_thread(p, global.number);
	while (i < global.number)
	{
		pthread_detach(p[i]->tid);
		i++;
	}


	while (global.number)
	{
		pthread_mutex_lock(&global.alive_mutex);
		if (global.dead)
		{

			pthread_mutex_unlock(&global.alive_mutex);
			break;
		}
		pthread_mutex_unlock(&global.alive_mutex);
	}
	if (global.time && global.number == 0)
	{
		ft_putstr_fd("eaten enough \n", 1);
	}

	i  =  0;
 
	return 0;
}
