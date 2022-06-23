# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 11:16:11 by sooyokim          #+#    #+#              #
#    Updated: 2022/06/22 09:29:42 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

NAME = libft server client
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: libft server_bonus client_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o 
	$(CC) -o $@ $< -L libft -lft

client: client.o
	$(CC) -o $@ $< -L libft -lft

server_bonus: server_bonus.o
	$(CC) -o $@ $< -L libft -lft

client_bonus: client_bonus.o
	$(CC) -o $@ $< -L libft -lft

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re