;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 10:40:13 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 12:55:45 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_isdigit

_ft_isdigit:
	cmp		rdi, 0x30
	jl		Lret
	cmp		rdi, 0x39
	jg		Lret
	mov		rax, 1
	ret

Lret:
	xor		rax, rax
	ret