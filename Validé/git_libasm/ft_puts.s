%define SYS_WRITE 0x2000004

section .data
nl		db 10

section .rodata
null		db "(null)", 10
len			equ $ - null

section .text
global		_ft_puts
extern		_ft_strlen

_ft_puts:
enter		8, 0
cmp			rdi, 0
je			retnull

write:
push		rdi
call		_ft_strlen
mov			rdx, rax
mov			rdi, 1
pop			rsi
mov			rax, SYS_WRITE
syscall

suite:
mov			rdi, 1
lea			rsi, [rel nl]
mov			rdx, 1
mov			rax, SYS_WRITE
syscall
jmp			end

retnull:
mov			rdi, 1
lea			rsi, [rel null]
mov			rdx, len
mov			rax, SYS_WRITE
syscall

end:
leave
ret
