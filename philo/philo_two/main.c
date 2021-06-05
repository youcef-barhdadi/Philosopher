/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:47:58 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/04 18:15:05 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long	get_time(void)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL))
		return (0);
	return (1000000 * start.tv_sec + start.tv_usec);
}

void	parse_args(int argc, char **argv, t_global *global)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat time_", 1);
		ft_putstr_fd("to_sleap [number_of_times_each_philospher_must_eat]\n", 1);
		exit(1);
	}
	global->number = ft_atoi(argv[1]);
	global->alive = global->number;
	global->to_die = ft_atoi(argv[2]) * 1000;
	global->to_eat = ft_atoi(argv[3]) * 1000;
	global->to_sleep = ft_atoi(argv[4]) * 1000;
	global->start = get_time();
	global->die = 0;
	if (argc == 6)
	{
		global->how = ft_atoi(argv[5]);
	}
}

void	mysleep(long target)
{
	long	start;

	start = get_time();
	while (get_time() - start < target)
		usleep(1);
}

void	lanch_thread(t_phili **thread, int number)
{
	int	i;
	int	num;

	i = 0;
	while (i < number)
	{
		num = pthread_create(&thread[i]->tid,
				NULL, start_phili, (void *) thread[i]);
		if (num != 0)
		{
			free_all(thread);
			return ;
		}
		i++;
	}
}

void	checkDeath(t_phili **listOfPhilo, t_global *global)
{
	int	i;

	i = -1;
	while (!global->die && global->number != global->eaten && ++i < global->number)
	{
		//  printf("%ld ÷  \n", get_time() - listOfPhilo[i]->last_meal );
		if (get_time() - global->to_die > listOfPhilo[i]->last_meal)
		{
			ft_message("DIE ", listOfPhilo[i]);
			global->die = 1;
			return ;
		}
		if (i == global->number - 1)
			i = 0;
	}
}

int	main (int argc, char **argv)
{
	t_global	*global;
	t_phili		**listOfPhilo;
	int			i;

	i = 0;
	global = malloc(sizeof(t_global));
	memset(global, 0, sizeof(t_global));
	parse_args(argc, argv, global);
	listOfPhilo = create_list(global);
	lanch_thread(listOfPhilo, global->number);
	checkDeath(listOfPhilo, global);
	i = -1;
	while (global->alive != 0 && ++i < global->number)
	{
		pthread_detach(listOfPhilo[i]->tid);
	}
	if (global->number == global->eaten)
		printf("kulchi kal\n");
	free_all(listOfPhilo);
	return (0);
}
