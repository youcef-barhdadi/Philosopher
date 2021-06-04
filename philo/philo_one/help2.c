/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:22:02 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/03 20:58:13 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void    ft_message(char *str, t_phili *phili)
{
    long stamp;

    pthread_mutex_lock(&phili->global->display);
    stamp =  get_time() - phili->global->start;
    printf("%ld  philopshper %d %s\n", stamp, phili->number, str);
    pthread_mutex_unlock(&phili->global->display);
}


void    mysleep(long target)
{
    long start;
    
    start = get_time();
    while (get_time() -  start < target)
        usleep(100);
}
