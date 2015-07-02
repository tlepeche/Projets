# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 02:02:34 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/05 18:19:24 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global _ft_bzero

_ft_bzero:
	enter 0,0
	cmp rsi, 0
	je sortie
	mov rcx, rsi
	jmp boucle

boucle:
	mov byte [rdi], 0
	inc rdi
	loop boucle
	jmp sortie

sortie:
	leave
	ret
