#ifndef _FT_PHILI_
#define _FT_PHILI_
# include <stdio.h>
# include <string.h>
#include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/time.h>
	typedef struct s_global
{
	int	number;
	unsigned long to_die;
	unsigned long to_eat;
	unsigned long to_sleep;
	int		dead;
	int		time;
	long 		start;
	pthread_mutex_t 	mutex;
	pthread_mutex_t alive_mutex;
unsigned how;
}		t_global;


typedef struct s_phili
{
	pthread_mutex_t take;
	pthread_mutex_t meal;
	pthread_t	tid;
	pthread_t	check;
	int		eat;
	int 		fork;
	int 		number;
	pthread_mutex_t mutex;
	pthread_mutex_t status;
	t_global *global;
	long long 	last_meal;
	struct s_phili 	*next;
	struct s_phili 	*perv;
	int	last;

}		t_phili;


# endif
