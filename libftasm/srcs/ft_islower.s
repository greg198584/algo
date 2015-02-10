# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 09:51:16 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 09:53:46 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_islower

_ft_islower:
	cmp		rdi, 0x61
	jl		Lret
	cmp		rdi, 0x7a
	jg		Lret
	mov		eax, 0x01
	ret

Lret:
	xor		eax, eax
	ret
