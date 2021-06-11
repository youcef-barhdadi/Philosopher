/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 07:48:43 by ybarhdad          #+#    #+#             */
/*   Updated: 2021/06/10 16:27:19 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

#define RED     "\033[31m"      /* Red */
 #define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

typedef struct s_global
{
	int				number;
	int				to_die;
	long			to_eat;
	long			to_sleep;
	long			start;
	int				how;
	int				eaten ;
	int				alive;
	int				die;
	pthread_mutex_t	display;
	pthread_mutex_t	eat_mutex;

}					t_global;

typedef struct s_phili
{
	pthread_mutex_t		take;
	pthread_mutex_t		meal;
	pthread_t			tid;
	pthread_t			check;
	int					eat;
	int					fork;
	int					number;
	pthread_mutex_t		mutex;
	pthread_mutex_t		status;
	long				last_meal;
	struct s_phili		*next;
	t_global			*global;
	struct s_phili		*perv;
	int					last;
	int					eating;
	int					done;

}				t_phili;

t_phili	**create_list(t_global *global);
void	*start_phili(void *a);
long	get_time(void);
void	ft_message(char *str, t_phili *phili);
void	mysleep(long target);
void	*start_phili(void *a);
void	free_all(t_phili **philo);
int		ft_atoi(const char *str);
char	*ft_itoa(int num);
void	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
char	*ft_lltoa(long long nbr);
int		ft_iswhitespace(int c);
void	eat(t_phili *phili);

#endif