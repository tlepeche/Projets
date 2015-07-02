# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 11:48:59 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:19:50 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
		global _ft_isalnum
		extern _ft_isalpha
		extern _ft_isdigit

_ft_isalnum:
	enter 0,0
	call _ft_isalpha
	cmp rax, 1
	je true
	call _ft_isdigit
	cmp rax, 1
	je true
	jmp false

true:
	mov rax, 1
	leave
	ret

false:
	mov rax, 0
	leave
	ret
