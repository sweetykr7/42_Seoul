# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:06:26 by sooyokim          #+#    #+#              #
#    Updated: 2022/04/19 10:29:36 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
HEADERS = includes

SRCS = srcs/ft_printf.c \
	   srcs/ft_print_chr_str.c \
	   srcs/ft_print_hexa.c \
	   srcs/ft_print_num.c \
	   srcs/ft_print_void_hexa.c  

OBJECTS = $(SRCS:.c=.o)

%o : %c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS) -I $(LIBDIR)

$(NAME) : $(OBJECTS)
	$(MAKE) all -C ./libft
	cp ./libft/libft.a ./$(NAME)
	ar -r $(NAME) $(OBJECTS)

all : $(NAME)

bonus : $(NAME)

clean :
	$(MAKE) -C ./libft clean
	rm -rf $(OBJECTS)

fclean :
	$(MAKE) -C ./libft fclean
	make clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
