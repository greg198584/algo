# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 21:24:02 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 22:09:52 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strlen

_ft_strlen:
	cmp		rdi, 0x00
	jle		Lret
	xor		rcx, rcx
	not		rcx
	cld

Lret:
	xor		rax, rax
	ret
