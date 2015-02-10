# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 19:39:06 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 19:42:01 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	call	_ft_isalpha
	cmp 	eax, 1
	je		Lret
	call	_ft_isdigit

Lret:
	ret
