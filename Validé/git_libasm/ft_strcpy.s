section .text
	global _ft_strcpy
	extern _ft_strncpy
	extern _ft_strlen

_ft_strcpy:
	enter 0,0
	mov r8, rdi
	push r8
	mov rdi, rsi
	push rsi
	call _ft_strlen
	mov rdx, rax
	inc rdx
	pop rsi
	pop rdi
	call _ft_strncpy
	leave
	ret
