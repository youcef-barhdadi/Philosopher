/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:59:23 by ybarhdad          #+#    #+#             */
/*   Updated: 2020/06/06 08:18:10 by ybarhdad         ###   ########.fr       */
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
	unsigned		eat;
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
