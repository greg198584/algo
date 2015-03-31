;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 15:53:08 by igomez            #+#    #+#              ;
;    Updated: 2015/01/31 15:53:59 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_memcpy

_ft_memcpy:
	push		rdi
	mov			rcx, rdx
	cld
	rep			movsb
	pop			rdi
	mov			rax, rdi
	ret