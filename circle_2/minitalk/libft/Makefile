# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:53:42 by sooyokim          #+#    #+#              #
#    Updated: 2022/06/20 14:13:52 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_atoi.c

CFLAGS	=	-Wall -Wextra -Werror
CC = cc
SRCS = $(SRC)
OBJECTS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
	ar -rc $@ $^

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re