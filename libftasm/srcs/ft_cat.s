# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 17:19:44 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 17:30:18 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_cat
	section	.text

_ft_cat:
	cmp		rdi, 0
	jl		Lret
	push	rdi

Lloop:
	pop		rdi
	lea		rsi, [rel buffer]
	mov		rdx, 0x1000
	mov		rax, 0x2000003
	syscall
	jc		Lret
	cmp		rax, 0x00
	je		Lret
	push	rdi
	mov		rdi, 0x1
	mov		rdx, rax
	mov		rax, 0x2000004
	syscall
	jc		Lret
	jmp		Lloop

Lret:
	ret

section		.bss
buffer:		resb 0x1000
