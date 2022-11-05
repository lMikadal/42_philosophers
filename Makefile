# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:59:29 by pmikada           #+#    #+#              #
#    Updated: 2022/11/05 14:59:32 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philosopher.c

MAIN = main.c

GCC = gcc

FLAG = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(FLAG) -o $(NAME) $(MAIN) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
