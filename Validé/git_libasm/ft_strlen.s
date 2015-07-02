section .text
	global _ft_strlen
	
_ft_strlen:
	enter 0,0
	mov rax, 0
	mov rcx, -1
	cld
	repnz scasb
	not rcx
	dec rcx
	mov rax, rcx
	leave
	ret
