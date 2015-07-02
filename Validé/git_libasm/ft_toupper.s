# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 12:04:11 by tlepeche          #+#    #+#              #
#    Updated: 2015/04/29 17:15:14 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_toupper
	extern _ft_islower

_ft_toupper:
	mov r8, rdi
	call _ft_islower
	cmp rax, 1
	jne unchanged
	sub r8, 32
	mov rax, r8
	ret

unchanged:
	mov rax, rdi
	ret
