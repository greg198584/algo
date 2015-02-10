# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 19:32:00 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 19:37:30 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isdigit

_ft_isdigit:
	cmp		rdi, 0x30
	jl		Lret
	cmp		rdi, 0x39
	jg		Lret
	mov		eax, 0x01
	ret

Lret:
	xor		eax, eax
	ret
