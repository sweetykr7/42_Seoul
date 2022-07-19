# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 14:46:02 by sooyokim          #+#    #+#              #
#    Updated: 2022/07/19 18:43:27 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes

MLXDIR = miniLibX
LIBMLX = libmlx.dylib

LIBFT_DIR = src/libft
MAIN_DIR = src/main
INPUT_DIR = src/input
FRACTOL_DIR = src/fractol
SRC_DIR = src
UTIL_DIR = src/utils



MLX_LNK = -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit -O3
LIBFT_LNK = -L $(LIBFT_DIR) -lft


SRCS = $(MAIN_DIR)/fractol.c $(MAIN_DIR)/initial_setting.c \
	   $(INPUT_DIR)/input_check.c $(INPUT_DIR)/atod_check.c \
	   $(FRACTOL_DIR)/mandelbrot.c $(FRACTOL_DIR)/julia.c $(FRACTOL_DIR)/burningship.c \
		$(SRC_DIR)/keyboard.c $(SRC_DIR)/mouse.c $(SRC_DIR)/zoom.c \
		$(SRC_DIR)/move.c $(SRC_DIR)/screen.c $(SRC_DIR)/render.c \
		$(UTIL_DIR)/terminate.c $(UTIL_DIR)/utils.c

OBJECTS = $(SRCS:.c=.o)

%o : %c
	$(MAKE) -C $(MLXDIR)
	cp $(MLXDIR)/$(LIBMLX) ./
	$(MAKE) all -C $(LIBFT_DIR)
	$(CC) -I $(MLXDIR) -I $(HEADERS) -I $(LIBFT_DIR) -c $< -o $@ -O3

$(NAME) : $(OBJECTS)
	$(CC) -o $@ $^ $(LIBFT_LNK) $(MLX_LNK) 

all : $(NAME)

bonus : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -rf $(LIBMLX)
	rm -rf $(OBJECTS)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	make clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re 