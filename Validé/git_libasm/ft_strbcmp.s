section .bss
	res: resb 1

section .text
	global _ft_strbcmp
	extern _ft_strlen

_ft_strbcmp:
	enter 0,0
	mov r10, rdi
	mov r11, rsi
	push r11
	push r10
	push rsi
	call _ft_strlen
	mov r8, rax		;r8 = strlen de s1
	pop rdi
	call _ft_strlen
	mov r9, rax		;r9 = strlen de s2
	pop rdi
	pop rsi
	cmp r8, 0
	je special1
	cmp r9, 0
	je special2
	cmp r8, r9
	jg s1			;go dans s1 si strlen(s1) >= strlen(s2)
	jmp s2

special1:
	cmp r9, 0
	je zero
	mov rax, -1
	leave
	ret

special2:
	cmp r8, 0
	je zero
	mov rax, 1
	leave
	ret

s2:
	mov rcx, r8
	jmp suite

s1:
	mov rcx, r9

suite:
	mov al, [rdi]
	mov cl,  al
	mov bl, [rsi]
	sub al, bl
	cmp al, 0
	jne end
	cmp rcx, 0
	je end
	inc rdi
	inc rsi
	loop suite

end:
	cmp al, 0
	jl minus_one
	je zero
	mov rax, 1
	leave
	ret

zero:
	mov rax, 0
	leave
	ret
	
minus_one:
	mov rax, -1
	leave
	ret
