# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_max.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 16:04:07 by glafitte          #+#    #+#              #
#    Updated: 2015/02/09 16:11:15 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_max

_ft_max:
	cmp		esi, edi
	jg		Lesi
	mov		eax, edi
	ret

Lesi:
	mov		eax, esi
	ret