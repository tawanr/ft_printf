# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/03/03 15:16:27 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c	\
		ft_itoa_base.c	\
		ft_itoa_u.c	\
		ft_printftype.c

BONUS_SRCS = ft_printf_bonus.c	\
				ft_itoa_base.c	\
				ft_itoa_u.c	\
				ft_printftype_bonus.c	\
				ft_flagformat_bonus.c	\
				ft_printf_padding_bonus.c	\
				ft_printf_flags_bonus.c

NAME = libftprintf.a
CC = gcc -Wextra -Wall -Werror
INCLUDES = ./libft/

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a ./$(NAME)
	@$(CC) -I $(INCLUDES) -c $(SRCS) 
	@ar -rcs $(NAME) *.o

clean:
	@$(MAKE) clean -C ./libft
	rm -rf *.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_SRCS) ft_printf.h ft_printf_bonus.h
	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a ./$(NAME)
	@$(CC) -I $(INCLUDES) -c $(BONUS_SRCS)
	@ar rcs $(NAME) *.o
