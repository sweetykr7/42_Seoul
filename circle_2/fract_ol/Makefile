# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 14:46:02 by sooyokim          #+#    #+#              #
#    Updated: 2022/07/18 19:07:23 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes

MLXDIR = miniLibX
LIBMLX = libmlx.dylib

LIBFT_DIR = src/libft

MLX_LNK = -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_LNK = -L $(LIBFT_DIR) -lft


#TESTDIR = src/test

SRCS = fractol.c keyboard.c zoom.c move.c screen.c

OBJECTS = $(SRCS:.c=.o)

%o : %c
	$(MAKE) -C $(MLXDIR)
	cp $(MLXDIR)/$(LIBMLX) ./
	$(MAKE) all -C $(LIBFT_DIR)
	$(CC) -I $(MLXDIR) -I $(HEADERS) -I $(LIBFT_DIR) -c $< -o $@

$(NAME) : $(OBJECTS)		
	$(CC) -o $@ $^ $(LIBFT_LNK) $(MLX_LNK) 

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	#$(MAKE) -C $(MLXDIR) clean
	#rm -rf $(LIBMLX)
	rm -rf $(OBJECTS)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	make clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 