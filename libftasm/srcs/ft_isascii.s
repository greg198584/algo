# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 19:43:24 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 19:44:21 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isascii

_ft_isascii:
	cmp		rdi, 0x00
	jl		Lret
	cmp		rdi, 0x7f
	jg		Lret
	mov		eax, 0x01
	ret

Lret:
	xor		eax, eax
	ret
