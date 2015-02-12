# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 17:07:37 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 17:17:53 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strdup
	extern	_ft_strlen
	extern	_malloc

_ft_strdup:
	cmp		rdi, 0x00
	je		Lerr
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	mov		rcx, rax
	push	rcx
	call	_malloc
	cmp		rax, 0x00
	je		Lerr
	pop		rcx
	pop		rsi
	mov		rdi, rax
	rep		movsb
	mov		byte [rdi + rcx], 0

Lerr:
	ret
