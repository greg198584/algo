;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 08:59:41 by igomez            #+#    #+#              ;
;    Updated: 2015/02/02 09:46:48 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax
	cmp		rdi, 0x0
	je		Lerr1
	cmp		rsi, 0x0
	je		Lerr2

Lloop:
	mov		al, [rdi]
	mov		bl, [rsi]
	cmp		al, bl
	jne		Ldiff
	cmp		al, 0x0
	je		Lret
	inc		rdi
	inc		rsi
	jmp		Lloop

Ldiff:
	cmp		al, bl
	jg		Lerr2

Lerr1:
	dec		rax
	ret

Lerr2:
	inc		rax
	ret

Lret:
	ret