;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 13:23:26 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 11:03:38 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_strlen

_ft_strlen:
	cmp		rdi, 0x0
	je		Lerr
	xor		rcx, rcx
	not		rcx
	cld
	xor		rax, rax
	repnz	scasb
	not		rcx
	dec		rcx
	mov		rax, rcx
	ret

Lerr:
	xor		rax, rax
	ret