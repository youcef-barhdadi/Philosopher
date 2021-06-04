/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:48:43 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/04 14:34:33 by ybarhdad         ###   ########.fr       */
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
     #include <sys/wait.h>
     #include <semaphore.h>
	      #include <signal.h>
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
	  int die;
    
}           t_global;



typedef struct s_phili
{
	  sem_t 	*take;
	  sem_t 	*meal;
	pid_t			pid;
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

}						t_phili;





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