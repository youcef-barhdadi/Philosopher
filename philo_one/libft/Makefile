# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 09:39:28 by ybarhdad          #+#    #+#              #
#    Updated: 2020/02/01 19:30:08 by ybarhdad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
HEADERS=libft.h
SRC=ft_strlen.c ft_memset.c	ft_memmove.c  ft_isprint.c ft_strrchr.c ft_strchr.c ft_memcpy.c ft_bzero.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isupper.c ft_islower.c \
	ft_memcmp.c ft_memccpy.c ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_strnstr.c ft_toupper.c ft_tolower.c ft_atoi.c ft_iswhitespace.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_strncmp.c ft_iswhitespace.c ft_strjoin.c  ft_strtrim.c ft_split.c ft_itoa.c  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c  \
	ft_putnbr_fd.c ft_strdup.c ft_substr.c ft_calloc.c \
	 ft_putendl_fd.c ft_lltoa.c  ft_lltoa_base.c ft_strequ.c ft_strnew.c ft_strdel.c ft_strnequ.c ft_strcount.c ft_dlstnew.c ft_dlstpush.c ft_dlstelemnew.c  ft_dlremovenode.c ft_dlstfind.c ft_dlstexist.c
BOU=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ=$(SRC:.c=.o)
BOBJ=$(BOU:.c=.o)
all:	$(NAME)
$(NAME):
		gcc -Wall -Werror -Wextra  -c $(SRC)
		ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)
bonus:	
		gcc -Wall -Werror  -Wextra -c $(SRC) $(BOU)
		ar -rc $(NAME) $(BOBJ) $(OBJ)
		ranlib $(NAME)
clean:
		/bin/rm -f *.o 
fclean:	clean
		rm -f $(NAME)
re:	fclean all
