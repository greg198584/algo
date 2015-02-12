# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 16:42:52 by glafitte          #+#    #+#              #
#    Updated: 2015/02/12 17:06:57 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_memcpy

_ft_memcpy:
	push	rdi
	mov		rcx, rdx
	cld
	rep		movsb
	pop		rdi
	mov		rax, rdi
	ret
