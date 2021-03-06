# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 21:24:02 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 08:11:21 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strlen

_ft_strlen:
	cmp		rdi, 0x00
	je		Lerr
	xor		rcx, rcx
	not		rcx
	xor		rax, rax
	cld
	repnz	scasb
	not 	rcx
	dec		rcx
	mov		rax, rcx
	ret

Lerr:
	xor		rax, rax
	ret
