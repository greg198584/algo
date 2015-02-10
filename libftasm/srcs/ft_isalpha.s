# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 19:09:34 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 19:21:18 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isalpha
	extern	_ft_isupper
	extern	_ft_islower

_ft_isalpha:
	call	_ft_isupper
	cmp 	eax, 1
	je		Lret
	call	_ft_islower

Lret:
	ret
