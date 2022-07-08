# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 15:13:46 by sooyokim          #+#    #+#              #
#    Updated: 2022/07/08 16:53:44 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes
INPUT_UTIL_DIR = src/input
SORT_DIR = src/sort
STACK_DIR = src/stack
ALGO_DIR = src/algo_opt
UTIL_DIR = src/util
PUSH_SWAP = src/push_swap

SOURCES = push_swap.c \
		$(INPUT_UTIL_DIR)/util_input1.c $(INPUT_UTIL_DIR)/util_input2.c \
		$(STACK_DIR)/util_divide_stack_a.c $(STACK_DIR)/util_divide_stack_b.c \
		$(STACK_DIR)/divide_stack_recur.c \
		$(STACK_DIR)/util_stack_1.c $(STACK_DIR)/util_stack_2.c\
		$(UTIL_DIR)/util_list.c $(UTIL_DIR)/util_print_buf.c \
		$(UTIL_DIR)/utils_1.c $(UTIL_DIR)/utils_2.c $(UTIL_DIR)/utils_3.c\
		$(UTIL_DIR)/get_pivot.c \
		$(ALGO_DIR)/algorithm_optimizing.c \
		$(ALGO_DIR)/algorithm_opt_case.c \
		$(ALGO_DIR)/algorithm_util_1.c \
		$(ALGO_DIR)/algorithm_util_2.c \
		$(SORT_DIR)/util_sort_a.c $(SORT_DIR)/util_sort_a_case.c \
		$(SORT_DIR)/util_sort_b.c $(SORT_DIR)/util_sort_b_case.c \
		$(SORT_DIR)/util_sort_check.c \
		$(SORT_DIR)/util_sort_optimize_3_case.c \
		$(SORT_DIR)/util_sort_optimize_3.c \
		$(SORT_DIR)/util_sort_optimize_5.c 
		
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJECTS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean:
	@rm -f $(OBJECTS)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re