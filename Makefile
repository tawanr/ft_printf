# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/02/20 18:05:34 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c	\
		main.c	\
		ft_itoa_base.c	\
		ft_itoa_u.c

NAME = libftprintf.a
CC = gcc -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	@$(CC) -c $(SRCS)
	@ar rcs $(NAME) libft.a *.o

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: $(BONUS_SRCS)
#	@$(CC) -c $(BONUS_SRCS)
#	@ar rcs $(NAME) *.o
