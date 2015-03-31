;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 13:14:19 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 13:15:55 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_tolower
	extern	_ft_isupper

_ft_tolower:
	call	_ft_isupper
	cmp		rax, 0
	je		Lret
	mov		rax, rdi
	add		rax, 0x20
	ret

Lret:
	mov		rax, rdi
	ret