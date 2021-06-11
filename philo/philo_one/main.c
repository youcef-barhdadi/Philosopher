/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:47:58 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/10 16:30:35 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_args(int argc, char **argv, t_global *global)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat time_", 1);
		ft_putstr_fd("to_sleap [number_of_times_each_philospher_must_eat]\n", 1);
		exit(1);
	}
	global->number = ft_atoi(argv[1]);
	if (global->number > 200)
	{
		perror("error");
		exit(0);
	}
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

void	lanch_thread(t_phili **thread, int number)
{
	int	i;
	int	num;
	int	j;

	j = 0;
	i = 0;
	while (i < number)
	{
		num = pthread_create(&thread[i]->tid,
				NULL, start_phili, (void *) thread[i]);
		if (num != 0)
		{
			while (j < i)
			{
				pthread_detach(thread[j]->tid);
				j++;
			}
			perror("philosphe 555r");
			exit(1);
		}
		i++;
	}
}

void deatch_thread(t_phili **phili)
{
	int	i;
	
	i = 0;
	while (i < phili[0]->global->number)
	{
		pthread_detach(phili[i]->tid);
		i++;
	}
}

void	checkDeath(t_phili **listOfPhilo, t_global *global)
{
	int	i;
	int j;

	i = -1;
	while (global->alive == global->number && ++i < global->number)
	{
			if (get_time() - global->to_die > listOfPhilo[i]->last_meal)
			{
				printf("%s", RED);
				ft_message("DIE ", listOfPhilo[i]);
				printf("%s", RESET);
				global->alive--;
				global->die = 1;
				deatch_thread(listOfPhilo);
				return ;
			}
		if (i == global->number - 1)
			i = 0;
		usleep(10);
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
	while (++i < global->number)
	{
		pthread_join(listOfPhilo[i]->tid, NULL);
	}
	if (global->number == global->eaten)
	{
		printf("%s", GREEN);
		printf("kulchi kal\n");
		printf("%s", RESET);

	}
	return (0);
}
