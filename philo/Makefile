# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 09:48:20 by pmikada           #+#    #+#              #
#    Updated: 2022/12/12 21:08:11 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philosopher.c philosopher2.c utils.c utils2.c

MAIN = main.c

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(FLAG) -o $(NAME) $(MAIN) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
