;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr_fd.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 12:32:08 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 12:41:37 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_putstr_fd
	extern	_ft_strlen

_ft_putstr_fd:
	mov		rdx, rsi
	mov		rsi, rdi
	call	_ft_strlen
	mov		rdi, rdx
	mov		rdx, rax
	mov		rax, 0x2000004
	syscall
	jc		Lerr
	ret

Lerr:
	mov		rax, 0
	ret