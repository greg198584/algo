# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 08:37:45 by glafitte          #+#    #+#              #
#    Updated: 2014/12/23 16:23:52 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ft_printf_test
INCLUDE = ../ft_printf
CFLAGS = -Wall -Werror -Wextra -g
LIBFTPRINTF = ../ft_printf
LIBFT = libft
SRCS = printf_test.c \
		main.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFTPRINTF) fclean
	@make -C $(LIBFTPRINTF)
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	gcc -I $(INCLUDE) -c $(SRCS)
	gcc $(OBJ) -L $(LIBFT) -lft -L $(LIBFTPRINTF) -lftprintf -o $(NAME)

clean :
	@make -C $(LIBFTPRINTF) clean
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFTPRINTF) fclean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
