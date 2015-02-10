# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 09:37:42 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 09:48:13 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isupper

_ft_isupper:
	cmp		rdi, 0x41
	jl		Lret
	cmp		rdi, 0x5a
	jg		Lret
	mov		eax, 0x01
	ret

Lret:
	xor		eax, eax
	ret
