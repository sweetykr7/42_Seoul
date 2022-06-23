# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:53:42 by sooyokim          #+#    #+#              #
#    Updated: 2022/03/21 14:37:10 by sooyokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
			ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
			ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c


BSRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c

CFLAGS	=	-Wall -Wextra -Werror

ifdef WITH_BONUS
	SRCS = $(SRC) $(BSRC)
	OBJECTS = $(SRCS:.c=.o)
else
	SRCS = $(SRC)
	OBJECTS = $(SRCS:.c=.o)
endif

OBJECTS_CLEAN_SRC = $(SRC) $(BSRC)
OBJECTS_CLEAN = $(OBJECTS_CLEAN_SRC:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJECTS)
	ar -rc $@ $^

bonus:
	@make WITH_BONUS=1 all

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS_CLEAN)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re