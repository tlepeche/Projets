section .text
	global	_ft_memalloc
	extern	_malloc
	extern	_ft_bzero

_ft_memalloc:
	enter 0,0
	cmp rdi, 0
	je null
	mov rsi, rdi
	push rsi
	call _malloc
	mov rdi, rax
	pop rsi
	call _ft_bzero
	leave
	ret

null:
	mov rax, 0
	leave
	ret
