# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 15:13:46 by sooyokim          #+#    #+#              #
#    Updated: 2022/07/11 19:23:09 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP) $(CHECKER)
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes
INPUT_UTIL_DIR = src/input
SORT_DIR = src/sort
STACK_DIR = src/stack
ALGO_DIR = src/algo_opt
UTIL_DIR = src/util
CHECKER_DIR = src/checker_util
GNL_DIR = src/gnl

PUSH_SWAP_ONLY_SOURCES = push_swap.c \
		$(ALGO_DIR)/algorithm_optimizing.c \
		$(ALGO_DIR)/algorithm_opt_case.c \
		$(ALGO_DIR)/algorithm_util_1.c \
		$(ALGO_DIR)/algorithm_util_2.c

SORT_SOURCES = $(SORT_DIR)/util_sort_a.c $(SORT_DIR)/util_sort_a_case.c \
		$(SORT_DIR)/util_sort_b.c $(SORT_DIR)/util_sort_b_case.c \
		$(SORT_DIR)/util_sort_check.c \
		$(SORT_DIR)/util_sort_optimize_3_case.c \
		$(SORT_DIR)/util_sort_optimize_3.c \
		$(SORT_DIR)/util_sort_optimize_5.c 

INPUT_SOURCES = $(INPUT_UTIL_DIR)/get_number.c \
		$(INPUT_UTIL_DIR)/util_input1.c $(INPUT_UTIL_DIR)/util_input2.c

STACK_SOURCES = $(STACK_DIR)/util_divide_stack_a.c \
		$(STACK_DIR)/util_divide_stack_b.c \
		$(STACK_DIR)/divide_stack_recur.c \
		$(STACK_DIR)/util_divide_stack_recur.c \
		$(STACK_DIR)/util_stack_1.c \
		$(STACK_DIR)/util_stack_2.c

UTIL_SOURCES = $(UTIL_DIR)/util_list.c $(UTIL_DIR)/util_print_buf.c \
		$(UTIL_DIR)/utils_1.c $(UTIL_DIR)/utils_2.c $(UTIL_DIR)/utils_3.c\
		$(UTIL_DIR)/utils_4.c \
		$(UTIL_DIR)/get_pivot.c


CHECKER_ONLY_SOURCES = checker.c \
		$(CHECKER_DIR)/checker_util_1.c \
		$(CHECKER_DIR)/instruction_check.c \
		$(CHECKER_DIR)/insert_instruction.c \
		$(CHECKER_DIR)/run_instruction.c \
		$(CHECKER_DIR)/checker_stack_1.c \
		$(CHECKER_DIR)/checker_stack_2.c \
		$(GNL_DIR)/get_next_line_utils.c \
		$(GNL_DIR)/get_next_line.c 

PUSH_SWAP_SOURCES = $(PUSH_SWAP_ONLY_SOURCES) $(INPUT_SOURCES) $(STACK_SOURCES) $(UTIL_SOURCES) $(SORT_SOURCES)
CHECKER_SOURCES = $(CHECKER_ONLY_SOURCES) $(INPUT_SOURCES) $(STACK_SOURCES) $(UTIL_SOURCES) $(SORT_SOURCES)

PUSH_SWAP_OBJECTS = $(PUSH_SWAP_SOURCES:.c=.o)
CHECKER_OBJECTS = $(CHECKER_SOURCES:.c=.o)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

all: $(NAME)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJECTS)

$(CHECKER) : $(CHECKER_OBJECTS)

clean:
	@rm -f $(PUSH_SWAP_OBJECTS)
	@rm -f $(CHECKER_OBJECTS)

fclean:		clean
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re