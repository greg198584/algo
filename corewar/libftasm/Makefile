#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <igomez@student.42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 09:03:16 by igomez            #+#    #+#              #
#    Updated: 2015/03/09 20:14:34 by glafitte         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

.SUFFIXES:

NAME = libft.a

#FLAGS

FLAGS = -Wall -Wextra -Werror
CFLAGS = $(FLAGS) -ansi -pedantic -std=c89

DEBUG = -g
SPEED = -g0 -O3

#COMPILE

ifeq ($(check), 1)
	CC = gcc $(CFLAGS) $(DEBUG)
else
	CC = gcc $(CFLAGS) $(SPEED)
endif

CCASM = nasm -f macho64 -g

#FOLDERS

FSRC = srcs
DSRC = $(FSRC)/
DOBJ = objs/
DINC = incs/

#SOURCES

CSRC = $(shell find $(FSRC) -type f -print | grep "\.c" | cut -d / -f2)
SSRC = $(shell find $(FSRC) -type f -print | grep "\.s" | cut -d / -f2)

#PATHSUB RULES

OBJ =  $(patsubst %.s, $(DOBJ)%.o, $(SSRC))
OBJ2 = $(patsubst %.c, $(DOBJ)%.o, $(CSRC))

#DEFAULT SHELL COMMAND

RMF = /bin/rm -f
RMD = /bin/rm -Rf
MKD = /bin/mkdir -p

all: $(NAME)

$(DOBJ)%.o: $(DSRC)%.s
	@$(MKD) $(DOBJ)
	@$(CCASM) -o $@ $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

$(DOBJ)%.o: $(DSRC)%.c
	@$(MKD) $(DOBJ)
	@$(CC) -o $@ -c $< -I $(DINC) \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

$(NAME): $(OBJ) $(OBJ2)
	@ar rcs $(NAME) $(OBJ) $(OBJ2) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "\n\t\t\t\b\b\033[0;31m\033[0;1m[%s]    \033[1;30m<<--\033[0;0m\n" "$@"

clean:
	@$(RMF) $(OBJ) $(OBJ2)
	@$(RMD) $(DOBJ)

fclean: clean
	@$(RMF) $(NAME)

re: fclean all
