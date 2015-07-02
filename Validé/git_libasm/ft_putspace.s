section .text
	global _ft_putspace

_ft_putspace:
	enter 0,0
	mov byte [r8], 32
	inc r8
	mov byte [r8], 0
	dec r8
	mov rcx, rdi

boucle:
	cmp rcx, 0
	je end
	push rcx
	mov rdi, 1
	lea rsi, [r8]
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	pop rcx
	dec rcx
	jmp boucle

end:
	leave
	ret
