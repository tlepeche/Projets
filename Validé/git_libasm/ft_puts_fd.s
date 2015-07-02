%define SYS_WRITE 0x2000004
%define STDOUT	rsi

section .data
nl		db 10

section .rodata
null		db "(null)", 10
len			equ $ - null

section .text
global		_ft_puts_fd
extern		_ft_strlen

_ft_puts_fd:
enter		8, 0
cmp			rdi, 0
je			retnull

write:
push		rdi
call		_ft_strlen
mov			rdx, rax
mov			rdi, STDOUT
pop			rsi
push		rdi
mov			rax, SYS_WRITE
syscall

suite:
pop			rdi
lea			rsi, [rel nl]
mov			rdx, 1
mov			rax, SYS_WRITE
syscall
jmp			end

retnull:
mov			rdi, STDOUT
lea			rsi, [rel null]
mov			rdx, len
mov			rax, SYS_WRITE
syscall

end:
leave
ret
