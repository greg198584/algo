;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar_fd.s                                    :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 14:12:20 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 14:21:30 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_putchar_fd
	extern	_ft_putstr_fd

_ft_putchar_fd:
	lea		rcx, [rel char]
	mov		[rcx], dil
	mov		rdi, rcx
	call	_ft_putstr_fd
	ret

section .bss
	char	resb 0x1