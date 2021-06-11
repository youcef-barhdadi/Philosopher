/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:47:58 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/11 19:09:20 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "ft_philo.h"



long	get_time(void)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL))
		return (0);
	return (1000000 * start.tv_sec + start.tv_usec);
}

void    parse_args(int argc, char **argv, t_global *global)
{
    if (argc != 5 && argc != 6)
    {
        ft_putstr_fd("number_of_philosophers time_to_die time_to_eat time_to_sleap [number_of_times_each_philospher_must_eat]\n", 1);
        exit(1);
    }

    global->number = ft_atoi(argv[1]);
    global->to_die = ft_atoi(argv[2]) * 1000;
    global->to_eat = ft_atoi(argv[3]) * 1000;
    global->to_sleep = ft_atoi(argv[4]) * 1000;
    global->die = 0;
    // printf("{{{%ld}}}}\n",    global->to_sleep );
    global->start = get_time();
    
    if (argc == 6)
    {
        global->how =  ft_atoi(argv[5]);
    }
}



t_phili **create_list(t_global *global)
{

    int i = 0;
    t_phili **list = malloc(global->number * sizeof(t_phili *));


    while (i < global->number)
    {
            
        list[i] = malloc(sizeof(t_phili));
        memset(list[i], 0, sizeof(t_phili));
    //    int re =  pthread_mutex_init(&list[i]->mutex , NULL);
        //  pthread_mutex_init(&list[i]->meal , NULL);

        // if (re != 0)
        // {
        //     perror("error ");
        //     exit(1);
        // }
        
   
        list[i]->number = i + 1;
        list[i]->last_meal = get_time();
        list[i]->global = global;
        if (i != 0)
        {
            list[i-1]->next = list[i];
            list[i]->perv = list[i-1];
        }
        i++;
    }

    list[0]->perv = list[global->number-1];
    list[global->number-1]->next =  list[0];
    sem_unlink("display1");
    global->display =  sem_open("display1",  O_CREAT | O_EXCL, 0666,1);
        printf("(%d)\n",(int)global->display);

    if (global->display  == SEM_FAILED)
    {
        perror("dd");
        exit(1);
    }
    sem_unlink("mutex14");
    global->mutex = sem_open("mutex14", O_CREAT | O_EXCL, 0666, global->number); 
    if (global->mutex  == SEM_FAILED)
    {
        perror("ff");
        exit(1);
    }
    list[global->number - 1]->next = list[0];
	list[global->number -1]->last = 1;
    return (list);
    
}


void ft_message(char *str, t_phili *phili)
{
    long stamp;

    sem_wait(phili->global->display);
    stamp =  get_time() - phili->global->start;
    printf("%ld  philopshper %d %s\n", stamp / 1000, phili->number, str);
    sem_post(phili->global->display);

}


void mysleep(long target)
{
    long start = get_time();
    while ( get_time() -  start < target )
        usleep(10);
    
}



void *check_death(void *a)
{   

    t_phili  *phili = (t_phili *)a;

    while  (1)
    {
        if (get_time() -  phili->last_meal > phili->global->to_die)
        {
                ft_message("DIE ", phili);
                phili->global->die = 1;
                exit(1);
        }
    }
    return NULL;
}

void check(t_phili *phili)
{
    if (phili->global->die != 0)
        exit(1);
}


void main_thread(void *a)
{
     t_phili  *phili = (t_phili *)a;
    int i =  pthread_create(&phili->checkDeath, NULL, check_death, (void *) phili);
    

}

void *start_phili(void *a)
{
   
     t_phili  *phili = (t_phili *)a;

    phili->last_meal = get_time();
    main_thread(phili);
    
    while (1)
    {
        ft_message("THINKING", phili);
        sem_wait(phili->global->mutex);
        check(phili);
		ft_message("TAKE A FORK", phili);
		ft_message("TAKE A FORK", phili);
		ft_message("EATING", phili);
		phili->eat ++;
    	phili->last_meal = get_time();
        mysleep(phili->global->to_eat );
        sem_post(phili->global->mutex);
        ft_message("SLEEPING", phili);
		mysleep(phili->global->to_sleep  );
        check(phili);
        if (phili->eat == phili->global->how)
        {
            break;
        }

    }
    if (phili->global->die == 1)
            exit(1);
    exit(0);
    return NULL;
}



 
void    lanch_thread(t_phili **thread, int number)
{

    int i;
    int status;
    int stat;
    
    i = 0;
    while (i < number)
    {
        thread[i]->pid = fork();
        if (thread[i]->pid == 0)
        {
              if (thread[i]->number % 2 == 0)
                mysleep(thread[i]->global->to_sleep );
            start_phili(thread[i]);
            exit(0);
        }
        else if(thread[i]->pid < 0){
            perror("fork error ");
        }
        i++;

    }
    int j = 0;
     i = 0;
int k = 0;
    while (waitpid(-1, &stat, 0 ) && thread[i]->global->eaten < thread[i]->global->number)
    {
        status = WEXITSTATUS(stat);
		if (status == 1){
			while (k < thread[0]->global->number)
				kill(thread[k++]->pid, SIGKILL);
                break ;
        }
        else {
                thread[0]->global->eaten++;
        }
      
    }
    
}

int main (int argc, char **argv)
{
    t_global *global = malloc(sizeof(t_global));
    memset(global, 0, sizeof(t_global));

   parse_args(argc, argv, global);
    t_phili **listOfPhilo = create_list(global);

    lanch_thread(listOfPhilo, global->number);
    int i = 0;
    int j  = 0;
    if (global->eaten == global->number)
        printf("Kulchi Kla\n"); 
    
    return 0;
}