# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 11:57:46 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:20:59 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
		global _ft_isprint

_ft_isprint:
	enter 0,0
	cmp rdi, 126
	jg false
	cmp rdi, 32
	jl false
	mov rax, 1
	leave
	ret

false:
	mov rax, 0
	leave
	ret
