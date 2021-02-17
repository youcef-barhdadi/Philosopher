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
    sem_wait(phili->global->display);
	stamp =  get_time()  - phili->global->start;
	number = ft_lltoa(stamp);
	ft_putstr_fd(number, 1);
	free(number);
	ft_putstr_fd(" philpspher ", 1);
	ft_putnbr_fd(phili->number, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
    sem_post(phili->global->display);

}
void *start_phili(void *a)
{
	t_phili *phili = (void *)a;
	while (1)
	{
		ft_message("THINGKING.", phili);


        sem_wait(phili->global->forks);
        //printf("fnf\n");
		ft_message("TAKE A FORK", phili);
        sem_wait(phili->global->forks);

		ft_message("TAKE A FORK", phili);
		ft_message("EATING", phili);
		phili->eat ++;
		//pthread_mutex_lock(&phili->meal);
		phili->last_meal = get_time();
		//pthread_mutex_unlock(&phili->meal);
		usleep(phili->global->to_eat);
        sem_post(phili->global->forks);
        sem_post(phili->global->forks);
		ft_message("SLEEPING", phili);
		usleep(phili->global->to_sleep);
	if (phili->global->time && phili->eat ==  phili->global->how)
			break ;

	}
    sem_wait(phili->global->mutex);
	phili->global->number--;
    sem_wait(phili->global->mutex);
	return NULL;
}


void*	check(void *data)
{

	t_phili *phili;

	phili = (t_phili *)data;

	while (phili->global->dead == 0  && phili->global->number != 0)
	{
		//pthread_mutex_lock(&phili->meal);
		long time = get_time() - phili->last_meal;
		if ( time > phili->global->to_die)
		{
			// printf("[%ld\n]\n", time);
            sem_wait(phili->global->alive_mutex);
			phili->global->dead = 1;
			ft_message("DEAED", phili);
            sem_post(phili->global->alive_mutex);
			usleep(1000);
			return 0;
		}
		//pthread_mutex_unlock(&phili->meal);
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
    printf("ff\n");

    global.mutex = sem_open("mutex1", O_CREAT, 0644, 1);


    
    if(global.mutex == SEM_FAILED) {
        perror("child sem_open");
        return 1;
    }
    global.display = sem_open("display1", O_CREAT, 0600, 1);
        if(global.display == SEM_FAILED) {
        perror("child sem_open");
        return 1;
    }
    global.alive_mutex = sem_open("alive_mutex1", O_CREAT, 0600, 1);
        if(global.alive_mutex  == SEM_FAILED) {
        perror("child sem_open");
        return 1;
    }
  
	parse_args(argc, argv, &global);
      global.forks = sem_open("aa11", O_CREAT, 0644, 4);
       if( global.forks  == SEM_FAILED) {
        perror("child sem_open");
        return 1;
    }
    
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
		// pthread_mutex_lock(&global.alive_mutex);
        sem_wait(global.alive_mutex);
		if (global.dead)
		{

        sem_post(global.alive_mutex);
			break;
		}
        sem_post(global.alive_mutex);
	}
	if (global.time && global.number == 0)
	{
		ft_putstr_fd("eaten enough \n", 1);
	}
	return 0;
}
