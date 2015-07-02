section .text
	global _ft_strncpy
	extern _ft_strlen

_ft_strncpy:
	enter 0,0
	cmp rdx, 0
	je end
	push rdi
	mov rdi, rsi
	push rsi
	push rdx
	call _ft_strlen
	pop rdx
	pop rsi
	pop rdi
	mov r8, rdx
	sub r8, rax
	mov rcx, rdx

boucle:
	cmp rcx, r8
	je b_zero
	mov al, [rsi]
	mov byte [rdi], al
	inc rsi
	inc rdi
	loop boucle
	mov rcx, rdx
	jmp backward

b_zero:
	mov al, 0
	mov byte [rdi], al
	inc rdi
	loop b_zero
	mov rcx, rdx

backward:
	dec rdi
	loop backward

end:
	mov rax, rdi
	leave
	ret
