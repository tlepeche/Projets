# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/26 17:16:00 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:20:08 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
		global	_ft_isalpha

_ft_isalpha:
	enter 0,0
	cmp rdi, 65
	jl false
	cmp rdi, 122
	jg false
	cmp rdi, 97
	jge true
	cmp rdi, 90
	jg false
	jmp true

true:
	mov rax, 1
	leave
	ret

false:
	mov rax, 0
	leave
	ret
