# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_min.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 15:31:52 by glafitte          #+#    #+#              #
#    Updated: 2015/02/09 15:37:08 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_min

_ft_min:
	cmp		esi, edi
	jl		Lesi
	mov		eax, edi
	ret

Lesi:
	mov		eax, esi
	ret