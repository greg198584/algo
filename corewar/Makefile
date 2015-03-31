# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/25 14:02:08 by glafitte          #+#    #+#              #
#    Updated: 2015/03/24 13:52:06 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE = -I include/ -I libftasm/incs/
LIBFT = ""
CC = gcc
SRCS =	vm/main.c \
		vm/option.c \
		vm/champ.c \
		vm/check_parser.c \
		vm/dump.c \
		vm/free_parser.c \
		vm/init.c \
		vm/number.c \
		vm/parser.c \
		vm/pos.c \
		vm/swap.c \
		vm/tools.c \
		vm/vm_parser.c \
		vm/print_in_mem.c \
		vm/tools_number.c \
		vm/cor.c \
		tools/op.c \
		tools/ft_fprintf.c \
		vm/result.c \
		vm/game/game.c \
		vm/game/add.c \
		vm/game/aff.c \
		vm/game/and.c \
		vm/game/fork.c \
		vm/game/fork_init.c \
		vm/game/ld.c \
		vm/game/ldi.c \
		vm/game/live.c \
		vm/game/lld.c \
		vm/game/lldi.c \
		vm/game/or.c \
		vm/game/st.c \
		vm/game/sti.c \
		vm/game/sub.c \
		vm/game/xor.c \
		vm/game/zjmp.c \
		vm/game/check_arg.c \
		vm/game/and_option.c \
		vm/game/and_option_2.c \
		vm/game/or_option.c \
		vm/game/or_option_2.c \
		vm/game/ldi_option.c \
		vm/game/xor_option.c \
		vm/game/xor_option_2.c \
		vm/game/sti_2.c \
		vm/game/lldi_option.c \
		vm/game/check_game.c \
		vm/game/dump_game.c \
		vm/game/check_instr.c \
		vm/game/dump_init.c \
		vm/game/carry.c \
		vm/game/init_variables.c \
		vm/game/debug.c \
		vm/game/debug_param.c \
		vm/game/cycle.c \
		\

define LIBFT_RULE
	make install_lib
endef

OBJ = $(SRCS:.c=.o)

all : 
	$(LIBFT_RULE)


include Makefile_cfg.mk

install_lib : $(MAKE_LIB)
				$(INSTALL)

MAKE_LIB:

libft: $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) -g -o $(NAME) -L $(LIBFT) -lft
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

nolibft: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBMLX)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) $(CFLAGS) $< -c $(SRCS)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re
