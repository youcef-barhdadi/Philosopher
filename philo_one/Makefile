NAME=philo_one
src= ft_atoi.c ft_lltoa.c ft_philo.h ft_putnbr_fd.c philo.c uitlits.c
obj=$(src::.c:.o)



$(NAME):
	gcc -Wall -Werror -Wextra -lpthread $(src) -o $(NAME)


clean:
	rm -f  $(obj) $(NAME)



