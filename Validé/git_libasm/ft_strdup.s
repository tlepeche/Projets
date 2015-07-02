section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

_ft_strdup:
	enter 0,0
	cmp rdi, 0
	je null
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	push rax
	call _malloc
	cmp rax, 0
	je	null 
	mov rdi, rax
	pop rcx
	pop rsi
	cld
	rep movsb
	leave
	ret

null:
	mov rax, 0
	leave
	ret
