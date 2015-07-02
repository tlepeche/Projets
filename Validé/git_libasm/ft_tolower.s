# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 12:04:11 by tlepeche          #+#    #+#              #
#    Updated: 2015/04/29 17:14:57 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_tolower
	extern _ft_isupper

_ft_tolower:
	mov r8, rdi
	call _ft_isupper
	cmp rax, 1
	jne unchanged
	add r8, 32
	mov rax, r8
	ret

unchanged:
	mov rax, rdi
	ret
