# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 20:56:23 by mbarylak          #+#    #+#              #
#    Updated: 2021/12/16 22:04:12 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = utils.c utils2.c push_swap.c errors.c ft_atoi.c movements.c \
	   movements2.c movements3.c order_small.c utils3.c logic.c \
	   logic2.c order_100.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -g3 -fsanitize=address

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
