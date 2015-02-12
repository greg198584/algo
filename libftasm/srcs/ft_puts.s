# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:00:11 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 12:16:33 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_puts
	extern	_ft_strlen

_ft_puts:
	cmp		rdi, 0x00
	je		Lnull
	push	rdi
	call	_ft_strlen
	pop		rsi
	mov		rdx, rax
	mov		rdi, 0x01
	mov		rax, 0x2000004
	syscall
	jc		Lerr
	mov		r9, rax
	lea		rsi, [rel bn]
	mov		rdi, 1
	mov 	rdx, 1
	mov 	rax, 0x2000004
	syscall
	jc		Lerr
	add 	rax, r9
	ret

Lnull:
	lea		rsi, [rel nerror]
	mov		rdi, 1
	mov		rdx, 7
	mov		rax, 0x2000004
	syscall
	jc		Lerr
	ret

Lerr:
	mov		rax, 0
	not		rax
	ret

segment	.data
	nerror	db "(null)", 10
	bn		db	10
