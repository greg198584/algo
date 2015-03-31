;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 12:30:08 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 12:49:39 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_isprint

_ft_isprint:
	cmp		rdi, 0x20
	jl		Lret
	cmp		rdi, 0x7e
	jg		Lret
	mov		rax, 0x1
	ret

Lret:
	xor		rax, rax
	ret