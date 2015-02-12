# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 08:12:42 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 10:58:16 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strcat

_ft_strcat:
	mov		rax, rdi
	mov		cl, [rax]
	cmp		cl, 0x00
	jz		_ft_start

_ft_getlen:
	inc		rax
	mov		cl, [rax]
	cmp		cl, 0x00
	jnz		_ft_getlen

_ft_start:
	sub		rax, rdi
	xor		rcx, rcx

_ft_loop:
	cmp		byte [rsi + rcx], 0x00
	jle		Lret
	mov		rdx, [rsi + rcx]
	mov		[rdi + rax], rdx
	inc		rax
	inc		rcx
	jmp	_ft_loop

Lret:
	mov		rdx, 0x00
	mov		[rdi + rax], rdx
	mov		rax, rdi
	ret
