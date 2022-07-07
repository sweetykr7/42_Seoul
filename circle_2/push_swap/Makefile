# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 15:13:46 by sooyokim          #+#    #+#              #
#    Updated: 2022/07/07 09:51:28 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = push_swap.c util_divide_stack_a.c util_divide_stack_b.c \
		util_input1.c util_input2.c \
		util_list.c util_print_buf.c \
		util_sort_a.c util_sort_a_case.c util_sort_b.c util_sort_b_case.c \
		util_sort_check.c \
		util_stack_1.c util_stack_2.c\
		utils_1.c utils_2.c \
		util_sort_a_optimize_case.c util_sort_a_optimize.c \
		divide_stack_recur.c get_pivot.c \
		algorithm_optimizing.c
		

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME)

$(NAME):	$(OBJECTS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re