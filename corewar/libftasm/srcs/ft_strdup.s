;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 16:02:14 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 16:10:27 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	cmp			rdi, 0x0
	je			Lerr
	push		rdi
	call		_ft_strlen
	mov			rdi, rax
	inc			rdi
	mov			rcx, rax
	push		rcx
	call		_malloc
	cmp			rax, 0x0
	je			Lerr
	pop			rcx
	pop			rsi
	mov			rdi, rax
	rep			movsb
	mov			byte [rdi + rcx], 0

Lerr:
	ret