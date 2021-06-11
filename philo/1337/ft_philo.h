/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:48:43 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/10 16:42:30 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PHILI_
#define _FT_PHILI_



# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h> 
     #include <semaphore.h>
typedef struct  s_global
{
     int number;
     int to_die;
     long to_eat;
     long to_sleep;
     long  start;
     int    how;
     int    eaten ;
    sem_t 	*mutex;
    sem_t *display;
	int alive;
	int die;
    
}           t_global;



typedef struct s_phili
{
	  sem_t 	*take;
	  sem_t 	*meal;
	pthread_t			tid;
	pthread_t			check;
	int			eat;
	int 				fork;
	int 				number;
	 
	  sem_t 	status;
	 long 				last_meal;
	struct s_phili 		*next;
    t_global            *global;
	struct s_phili 		*perv;
	int					last;
	int					done;

}						t_phili;

void mysleep(long target);
void    ft_message(char *str, t_phili *phili);
void	free_all(t_phili **philo);
t_phili	**create_list(t_global *global);
void *start_phili(void *a);
long get_time();
int		ft_atoi(const char *str);
char	*ft_itoa(int num);
void	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
char	*ft_lltoa(long long nbr);
int		ft_iswhitespace(int c);

# endif