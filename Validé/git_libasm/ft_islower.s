# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 12:02:21 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:20:45 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_islower

_ft_islower:
	enter 0,0
	cmp rdi, 97
	jl false
	cmp rdi, 122
	jg false
	mov rax, 1
	leave
	ret

false:
	mov rax, 0
	leave
	ret
