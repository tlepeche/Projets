section .text
	global _ft_memset

_ft_memset: 
	enter 0,0
	cmp rdx, 0
	je end
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	mov rcx, rdx
	jmp backward
	
backward:
	dec rdi
	loop backward
	jmp end

end:
	mov rax, rdi
	leave
	ret
