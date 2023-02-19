	.file	"lab5.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"\320\236\321\210\320\270\320\261\320\272\320\260, \320\277\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\262\320\262\320\276\320\264: "
	.text
	.globl	input
	.type	input, @function
input:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$-1, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	jmp	.L2
.L4:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L3:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L3
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
.L2:
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	jle	.L4
	movl	-16(%rbp), %eax
	cmpl	$100, %eax
	jg	.L4
	cmpl	$0, -12(%rbp)
	je	.L4
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	input, .-input
	.section	.rodata
.LC3:
	.string	"\320\273\320\265\321\202"
.LC4:
	.string	"\320\263\320\276\320\264"
.LC5:
	.string	"\320\263\320\276\320\264\320\260"
	.text
	.globl	ret
	.type	ret, @function
ret:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%edx, %esi
	sarl	$31, %esi
	subl	%esi, %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, -4(%rbp)
	cmpl	$10, -20(%rbp)
	jle	.L8
	cmpl	$19, -20(%rbp)
	jle	.L9
.L8:
	movl	-4(%rbp), %eax
	jmp	.L10
.L9:
	movl	$5, %eax
.L10:
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L11
	cmpl	$4, -4(%rbp)
	jle	.L12
.L11:
	leaq	.LC3(%rip), %rax
	jmp	.L13
.L12:
	cmpl	$1, -4(%rbp)
	jne	.L14
	leaq	.LC4(%rip), %rax
	jmp	.L13
.L14:
	leaq	.LC5(%rip), %rax
.L13:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	ret, .-ret
	.section	.rodata
	.align 8
.LC6:
	.string	"\321\201\320\276\320\262\320\265\321\200\321\210\320\265\320\275\320\275\320\276\320\273\320\265\321\202\320\275\320\270\320\271"
.LC7:
	.string	"\320\277\320\265\320\275\321\201\320\270\320\276\320\275\320\265\321\200"
	.align 8
.LC8:
	.string	"\321\201\320\276\320\262\320\265\321\200\321\210\320\265\320\275\320\275\320\276\320\273\320\265\321\202\320\270\321\217"
.LC9:
	.string	"\320\277\320\265\320\275\321\201\320\270\320\270"
.LC10:
	.string	"\320\222\321\213 %s\n"
.LC11:
	.string	"\320\222\320\260\320\274 %d %s \320\264\320\276 %s\n"
.LC12:
	.string	"\320\222\321\213 \321\203\320\266\320\265 %d %s %s\n"
	.text
	.globl	output
	.type	output, @function
output:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	cmpl	$1, -40(%rbp)
	jne	.L16
	leaq	.LC6(%rip), %rax
	jmp	.L17
.L16:
	leaq	.LC7(%rip), %rax
.L17:
	movq	%rax, -16(%rbp)
	cmpl	$1, -40(%rbp)
	jne	.L18
	leaq	.LC8(%rip), %rax
	jmp	.L19
.L18:
	leaq	.LC9(%rip), %rax
.L19:
	movq	%rax, -8(%rbp)
	cmpl	$1, -40(%rbp)
	jne	.L20
	movl	$18, %eax
	jmp	.L21
.L20:
	movl	$60, %eax
.L21:
	movl	%eax, -24(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	.L22
	movl	$1, %eax
	jmp	.L23
.L22:
	movl	$2, %eax
.L23:
	movl	%eax, -20(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	.L24
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L28
.L24:
	cmpl	$1, -20(%rbp)
	je	.L26
	cmpl	$2, -20(%rbp)
	je	.L27
	jmp	.L28
.L26:
	movl	-24(%rbp), %eax
	subl	-36(%rbp), %eax
	movl	%eax, %edi
	call	ret
	movq	%rax, %rsi
	movl	-24(%rbp), %eax
	subl	-36(%rbp), %eax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movl	%eax, %esi
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L25
.L27:
	movl	-36(%rbp), %eax
	subl	-24(%rbp), %eax
	movl	%eax, %edi
	call	ret
	movq	%rax, %rsi
	movl	-36(%rbp), %eax
	subl	-24(%rbp), %eax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movl	%eax, %esi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L25:
.L28:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	output, .-output
	.section	.rodata
.LC13:
	.string	"\320\222\320\260\320\274 %d %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	input
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	ret
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	$1, %esi
	movl	%eax, %edi
	call	output
	movl	-12(%rbp), %eax
	movl	$2, %esi
	movl	%eax, %edi
	call	output
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
