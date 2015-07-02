%define BUFF_SIZE 128
%define READ	0x2000003
%define WRITE	0x2000004

section .text
	global _ft_cat

_ft_cat:
	enter BUFF_SIZE,0
	cmp rdi, -1
	je sortie

start:
	mov rsi, rsp
	mov rdx, BUFF_SIZE
	mov rax, READ
	syscall
	jc sortie
	cmp rax, 0
	je sortie
	push rdi

suite:
	mov rdi, 1
	mov rdx, rax
	mov rax, WRITE
	syscall
	pop rdi
	jc sortie
	jne start

sortie:
	leave
	ret
