;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/29 15:22:57 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 13:15:00 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_bzero

_ft_bzero:
	cmp		rsi, 0x0
	jle		Lret

Lloop:
	dec		rsi
	mov		byte [rdi+rsi], 0x0
	jmp		_ft_bzero

Lret:
	ret