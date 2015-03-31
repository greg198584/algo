;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/29 18:02:58 by igomez            #+#    #+#              ;
;    Updated: 2015/01/29 18:07:39 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_isalpha
	extern	_ft_isupper
	extern	_ft_islower

_ft_isalpha:
	call	_ft_isupper
	cmp		rax, 1
	je		Lret
	call	_ft_islower

Lret:
	ret