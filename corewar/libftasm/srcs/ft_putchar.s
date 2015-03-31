;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 12:42:01 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 13:25:57 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_putchar
	extern	_ft_putstr

_ft_putchar:
	lea		rcx, [rel char]
	mov		[rcx], dil
	mov		rdi, rcx
	call	_ft_putstr
	ret

section .bss
	char	resb 0x1