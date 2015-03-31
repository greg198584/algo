;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 13:08:22 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 13:13:41 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_toupper
	extern	_ft_islower

_ft_toupper:
	call	_ft_islower
	cmp		rax, 0
	je		Lret
	mov		rax, rdi
	sub		rax, 0x20
	ret

Lret:
	mov		rax, rdi
	ret