section .text
	global _ft_isspace

_ft_isspace:
	enter 0,0
	cmp rdi, 32	;' '
	je good
	cmp rdi, 9	;'\t'
	je good
	cmp rdi, 10	;'\n'
	je good
	cmp rdi, 11	;'\v'
	je good
	cmp rdi, 12	;'\f'
	je good
	cmp rdi, 13	;'\r'
	je good
	mov rax, 0
	leave
	ret

good:
	mov rax, 1
	leave
	ret
