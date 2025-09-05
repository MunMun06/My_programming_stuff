	.file	"rosetta.cpp"
	.text
	.globl	_Z12returny_funcPicsi
	.type	_Z12returny_funcPicsi, @function
_Z12returny_funcPicsi:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%edx, %eax
	movl	%ecx, -20(%rbp)
	movl	%esi, %edx
	movb	%dl, -12(%rbp)
	movw	%ax, -16(%rbp)
	movsbl	-12(%rbp), %edx
	movswl	-16(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z12returny_funcPicsi, .-_Z12returny_funcPicsi
	.section	.rodata
.LC0:
	.string	"done:)\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$-4990328140781978930, %rax
	movq	%rax, -24(%rbp)
	movl	$-559026163, -32(%rbp)
	movl	$1953724781, -14(%rbp)
	movw	$114, -10(%rbp)
	movl	$1337, -36(%rbp)
	jmp	.L4
.L5:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -36(%rbp)
.L4:
	movl	-36(%rbp), %eax
	testl	%eax, %eax
	jne	.L5
	leaq	-36(%rbp), %rax
	movl	$201527, %ecx
	movl	$105, %edx
	movl	$66, %esi
	movq	%rax, %rdi
	call	_Z12returny_funcPicsi
	movl	%eax, -28(%rbp)
	leaq	.LC0(%rip), %rax
	movl	$7, %ecx
	movq	%rax, %rdx
	movl	$1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	syscall@PLT
	movl	$32, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.1.1 20250425"
	.section	.note.GNU-stack,"",@progbits
