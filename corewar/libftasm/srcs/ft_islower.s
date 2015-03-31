;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_islower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/29 17:58:38 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 12:56:14 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_islower

_ft_islower:
	cmp		rdi, 0x61
	jl		Lret
	cmp		rdi, 0x7a
	jg		Lret
	mov		rax, 1
	ret

Lret:
	xor		rax, rax
	ret