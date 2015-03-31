# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_cfg.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/14 12:59:34 by glafitte          #+#    #+#              #
#    Updated: 2015/03/31 07:58:21 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override define LIBFT_RULE
	@make usage
endef

usage:
	@echo "---[ Usage ]--"
	@echo "\nindiquer dans le Makefile_cfg ou ce trouve votre lib."
	@echo "choisir si oui ou non vous voulait la compiler"
	@echo "\n\t make 033[37;1m[\033[32m libft \033[37m]\033[0m"
	@echo "\t make 033[37;1m[\033[32m nolibft \033[37m]\033[0m"

lift_init:
	$(eval LIBFT = "./libftasm/")
libft: lift_init install_lib
