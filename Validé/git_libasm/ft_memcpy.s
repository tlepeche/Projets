# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 19:09:53 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 16:06:42 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_memcpy

_ft_memcpy:
	enter 0,0
	mov rax, rdi
	cmp rdx, 0
	je null
	mov rcx, rdx
	cld
	rep movsb
	leave
	ret

null:
	leave
	ret
