;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/29 16:38:07 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 12:41:45 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_putstr
	extern	_ft_strlen

_ft_putstr:
	mov		rsi, rdi
	call	_ft_strlen
	mov		rdx, rax
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall
	jc		Lerr
	ret

Lerr:
	mov		rax, 0
	ret