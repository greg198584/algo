;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/29 17:40:45 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 12:56:28 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_isupper

_ft_isupper:
	cmp		rdi, 0x41
	jl		Lret
	cmp		rdi, 0x5a
	jg		Lret
	mov		rax, 1
	ret

Lret:
	xor		rax, rax
	ret