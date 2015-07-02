# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 11:43:48 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:20:31 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isdigit

_ft_isdigit:
	enter 0,0
	cmp rdi, 48
	jl sortie
	cmp rdi, 57
	jg sortie
	mov rax, 1
	leave
	ret

sortie:
	mov rax, 0
	leave
	ret
