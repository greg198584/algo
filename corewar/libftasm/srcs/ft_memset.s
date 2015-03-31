;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 15:12:55 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 15:16:36 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_memset

_ft_memset:
	push		rdi
	mov			rax, rsi
	mov			rcx, rdx
	cld
	rep			stosb
	pop			rdi
	mov			rax, rdi
	ret