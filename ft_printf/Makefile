# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 11:11:25 by glafitte          #+#    #+#              #
#    Updated: 2015/01/19 16:57:58 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g -I include/
LIBFT = libft
CC = gcc
SRCS =			src/ft_printf.c \
				src/ft_putnbr_hexa.c \
				src/ft_atoi_base.c \
				src/ft_get_base.c \
				src/ft_strpos.c \
				src/ft_convert_base.c \
				src/ft_option.c \
				src/ft_atoui.c \
				src/ft_uitoa.c \
				src/ft_uint.c \
				src/ft_string.c \
				src/ft_precision.c \
				src/ft_print_string.c \
				src/ft_atof.c \
				src/ft_ftoa.c \
				\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT) re
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) -I include/ $< -c $(SRCS) -L $(LIBFT) -lft

clean :
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
