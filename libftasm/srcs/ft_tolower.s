# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 21:18:08 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 21:19:37 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_tolower
	extern	_ft_isupper

_ft_tolower:
	call	_ft_isupper
	cmp		rax, 0x00
	je		Lret
	mov		rax, rdi
	add		rax, 0x20
	ret

Lret:
	mov 	rax, rdi
	ret
