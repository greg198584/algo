# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 14:51:34 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 16:37:34 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_memset

_ft_memset:
	push	rdi
	mov		rax, rsi
	mov		rcx, rdx
	cld
	rep		stosb
	pop		rdi
	mov		rax, rdi
	ret
