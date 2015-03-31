;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 11:31:34 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 12:57:32 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_isascii

_ft_isascii:
	cmp		rdi, 0x0
	jl		Lret
	cmp		rdi, 0x7f
	jg		Lret
	mov		rax, 0x1
	ret

Lret:
	xor		rax, rax
	ret