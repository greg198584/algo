# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 17:01:09 by glafitte          #+#    #+#              #
#    Updated: 2015/02/09 17:02:36 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_bzero

_ft_bzero:
	cmp		rsi, 0x0
	jle		Lret

Lloop:
	dec		rsi
	mov	byte [rdi+rsi], 0x0
	jmp		_ft_bzero

Lret:
	ret
