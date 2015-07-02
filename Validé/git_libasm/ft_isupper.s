# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 14:16:33 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:21:15 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isupper

_ft_isupper:
	enter 0,0
	cmp rdi, 65
	jl false
	cmp rdi, 90
	jg false
	mov rax, 1
	leave
	ret

false:
	mov rax, 0
	leave
	ret
