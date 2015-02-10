# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 20:38:30 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 20:41:05 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isprint

_ft_isprint:
	cmp		rdi, 0x20
	jl		Lret
	cmp		rdi, 0x7e
	jg		Lret
	mov		eax, 0x01
	ret

Lret:
	xor		eax, eax
	ret
