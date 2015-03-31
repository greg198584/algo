;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 10:30:36 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 17:30:31 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	mov		rax, rdi
	mov		cl, [rax]
	cmp		cl, 0x0
	jz		Lstart

Lgetlen:
	inc		rax
	mov		cl, [rax]
	cmp		cl, 0x0
	jnz		Lgetlen

Lstart:
	sub		rax, rdi
	xor		rcx, rcx

Lloop:
	cmp		byte [rsi + rcx], 0x0
	jle		Lret
	mov		rdx, [rsi + rcx]
	mov		[rdi + rax], rdx
	inc		rcx
	inc		rax
	jmp		Lloop

Lret:
	mov		rdx, 0x0
	mov		[rdi + rax], rdx
	mov		rax, rdi
	ret