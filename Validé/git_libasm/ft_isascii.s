# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/24 19:37:11 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:20:20 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
		global	_ft_isascii

_ft_isascii:	
	enter 0,0
	cmp rdi, 127
	jg	sortie
	cmp rdi, 0
	jl	sortie
	mov	rax, 1
	leave
	ret
		
sortie:	
	mov	rax, 0
	leave
	ret
