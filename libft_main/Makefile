#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 08:42:35 by igomez            #+#    #+#              #
#    Updated: 2014/11/07 10:20:57 by igomez           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, clean, fclean, re

NAME = unit_test
CC = cc
CFLAGS = -Wall -Werror -Wextra -pedantic -O3 -I./..
LDFLAGS = -L./../libft -lft
SOURCE = main.c unit_test.c
OBJ = $(SOURCE:.c=.o)

all : $(NAME)


$(NAME): $(OBJ) ../libft/libft.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

../libft/libft.a:
	@make -C ..