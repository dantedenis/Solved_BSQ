# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstrong <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 11:01:13 by bstrong           #+#    #+#              #
#    Updated: 2021/08/31 12:50:53 by bstrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= bsq
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= -Wall -Werror -Wextra
SRC		= $(wildcard src/*.c)
HEADER	= inc/
OBJS	= $(SRC:.c=.o)

.PHONY: all clean fclean re

all		: $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(LFLAGS) -o $(NAME) $(SRC) -I $(HEADER)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)

clean	:
	@/bin/rm -f $(OBJS)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all
