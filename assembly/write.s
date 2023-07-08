
	.global _start

_start:
	mov $1, %rax
	mov $1, %rdi
	mov $txt, %rsi
	mov $10, %rdx
	syscall

	mov $60, %rax
	xor %rdi, %rdi
	syscall

txt:

	.ascii "Hi Tarokh\n"
