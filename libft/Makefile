# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/02/15 23:45:11 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c	\
		ft_strchr.c	\
		ft_strdup.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c	\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c	\
		ft_tolower.c	\
		ft_toupper.c

BONUS_SRCS = ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c	\
			ft_lstdelone.c	\
			ft_lstiter.c	\
			ft_lstlast.c	\
			ft_lstmap.c	\
			ft_lstnew.c	\
			$(SRCS)

NAME = libft.a
CC = gcc -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@$(CC) -c $(SRCS)
	@ar rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_SRCS)
	@$(CC) -c $(BONUS_SRCS)
	@ar rcs $(NAME) *.o
