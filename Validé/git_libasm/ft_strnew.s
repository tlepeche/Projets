section .text
	global	_ft_strnew
	extern	_ft_memalloc

_ft_strnew:
	enter 0,0
	inc rdi
	call _ft_memalloc
	leave
	ret
