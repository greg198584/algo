# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 21:13:41 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 21:17:21 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_toupper
	extern	_ft_islower

_ft_toupper:
	call	_ft_islower
	cmp		rax, 0x00
	je		Lret
	mov		rax, rdi
	sub		rax, 0x20
	ret

Lret:
	mov 	rax, rdi
	ret
