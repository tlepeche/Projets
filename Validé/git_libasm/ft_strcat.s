section .text
	global _ft_strcat

_ft_strcat:
	enter 0,0
	mov r9, 0
	cmp rdi, 0
	je copy

boucle:
	cmp byte [rdi], 0
	je copy
	inc r9
	inc rdi
	jmp boucle
	
copy:
	cmp byte [rsi], 0
	je sortie
	mov al, [rsi]
	mov byte [rdi], al
	inc r9
	inc rdi
	inc rsi
	jmp copy		

sortie:
	mov byte [rdi], 0

backward:
	cmp r9, 0
	je end
	dec rdi
	dec r9
	jmp backward

end:
	mov rax, rdi
	leave
	ret
