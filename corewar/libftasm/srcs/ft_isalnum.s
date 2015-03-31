;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/30 10:51:50 by igomez            #+#    #+#              ;
;    Updated: 2015/01/30 10:54:25 by igomez           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	call	_ft_isdigit
	cmp		rax, 1
	je		Lret
	call	_ft_isalpha

Lret:
	ret