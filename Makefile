# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 18:30:43 by mbarylak          #+#    #+#              #
#    Updated: 2022/01/26 18:28:53 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = utils.c utils2.c errors.c ft_atoi.c push_swap.c movements.c \
	   movements2.c movements3.c lstutils.c lstutils2.c order_small.c \
	   utils3.c order_big.c order_big2.c 

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -g3 -fsanitize=address

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
