/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:03:11 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/04 20:26:59 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"



void    ft_message(char *str, t_phili *phili)
{
    long stamp;

    sem_wait(phili->global->display);
    stamp =  get_time() - phili->global->start;
    printf("%ld  philopshper %d %s\n", stamp / 1000, phili->number, str);
    sem_post(phili->global->display);
}

void	eat(t_phili *phili)
{
	ft_message("TAKE A FORK", phili);
	ft_message("TAKE A FORK", phili);
	ft_message("EATING", phili);
	phili->eat++;
	phili->last_meal = get_time();
	mysleep(phili->global->to_eat);
}

void	free_all(t_phili **philo)
{
	int	i;

	i = 0;
    sem_unlink("display");
    sem_unlink("mutex");
	while (i < philo[0]->global->number)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
	exit(0);
}
# include <errno.h>

void *start_phili(void *a)
{
    t_phili  *phili = (t_phili *)a;

    if (phili->number % 2 == 0)
        mysleep(phili->global->to_eat);
    phili->last_meal = get_time();
    while (!phili->global->die && phili->global->number != phili->global->eaten)
    {
        ft_message("THINKING", phili);
        sem_wait(phili->global->mutex);
     
       eat(phili);
		sem_post(phili->global->mutex);

		mysleep(phili->global->to_sleep  );
        ft_message("SLEEPING", phili);
        if (phili->eat == phili->global->how)
        {
            phili->global->eaten++;
            break ;
        }
    }    
    return NULL;
}

void	create_thread(t_global *global, t_phili **list, int i)
{
	int		re;

	list[i] = malloc(sizeof(t_phili));
	memset(list[i], 0, sizeof(t_phili));
    sem_unlink("/mutex");
	if ((global->mutex = sem_open("/mutex",  O_CREAT, 0666, global->number / 2 )) == SEM_FAILED)
		exit(0);
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
	list = malloc(global->number * sizeof(t_phili *));
	while (i < global->number)
	{
		create_thread(global, list, i);
		i++;
	}
	list[0]->perv = list[global->number - 1];
	list[global->number - 1]->next = list[0];
    sem_unlink("display");
	list[0]->global->display =  sem_open("display",O_CREAT, 0666,1 );
	list[global->number - 1]->next = list[0];
	list[global->number - 1]->last = 1;
	return (list);
}