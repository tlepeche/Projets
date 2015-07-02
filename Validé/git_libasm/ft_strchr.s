section .text
	global _ft_strchr
	extern _ft_strlen

_ft_strchr:
	enter 0,0
	mov r9, rdi
	push r9
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
		push rsi
	call _ft_strlen
	mov rcx, rax
	inc rcx
	pop rsi
	pop rdi
	mov rax, rsi
	cld
	repnz scasb

find:
	dec rdi
	cmp byte [rdi], 0
	je end
	mov rax, rdi
	leave
	ret

end:
	mov rax, 0
	leave
	ret
