# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 21:24:02 by glafitte          #+#    #+#              #
#    Updated: 2015/02/10 21:44:42 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp,rsp
	mov		QWORD PTR [rbp-0x8],rdi
	mov    DWORD PTR [rbp-0	xc],0xffffffff
	mov    eax,DWORD PTR [rbp-0	xc]
	add    eax,0x1
	mov    DWORD PTR [rbp-0xc],eax
	movsx		d rcx,eax
	mov    rdx,QWORD PTR [rbp-0x8]
	movsx  eax,BYTE PTR [rdx+rcx*1]
	cmp    eax,0x0
	je     0xf55 <ft_strlen+53>
	jmp    0x100000f2	f <ft_strlen+15>
	mov    eax,DWORD PTR [rbp	-0xc]
	pop    rbp
	ret
