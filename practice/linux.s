	.file	"counting2.c"
	.text
	.section	.rodata
.LC0:
	.string	"malloc failed"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"%d "
	.text
	.globl	sort
	.type	sort, @function
sort:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	movq	%rdi, -120(%rbp)
	movl	%esi, -124(%rbp)
	movl	%edx, -128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	-128(%rbp), %eax
	addl	$1, %eax
	cltq
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -80(%rbp)
	movl	-124(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	cmpq	$0, -80(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
.L2:
	movl	-128(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -88(%rbp)
	jmp	.L3
.L4:
	movl	-88(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$1, -88(%rbp)
.L3:
	movl	-88(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.L4
	movl	$10, %edi
	call	putchar@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$0, -92(%rbp)
	jmp	.L5
.L6:
	movl	-92(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -92(%rbp)
.L5:
	movl	-92(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.L6
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, -96(%rbp)
	jmp	.L7
.L8:
	movl	-96(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-96(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-120(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-80(%rbp), %rax
	addq	%rcx, %rax
	addl	$1, %edx
	movl	%edx, (%rax)
	movl	-96(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	-64(%rbp), %rax
	movl	-96(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -96(%rbp)
.L7:
	movl	-96(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jl	.L8
	movl	$0, -100(%rbp)
	jmp	.L9
.L10:
	movl	-100(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -100(%rbp)
.L9:
	movl	-100(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.L10
	movl	$10, %edi
	call	putchar@PLT
	movl	$1, -104(%rbp)
	jmp	.L11
.L12:
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-104(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rsi
	movq	-80(%rbp), %rax
	addq	%rsi, %rax
	addl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -104(%rbp)
.L11:
	movl	-104(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.L12
	movl	-124(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -84(%rbp)
	jmp	.L13
.L14:
	movq	-64(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	-64(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	leal	-1(%rcx), %edx
	movl	%edx, (%rax)
	movl	-84(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movq	-64(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, (%rcx)
	subl	$1, -84(%rbp)
.L13:
	cmpl	$0, -84(%rbp)
	jns	.L14
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	%rbx, %rsp
	nop
	movq	-56(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
	.size	sort, .-sort
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -32(%rbp)
	movl	$9, -28(%rbp)
	movl	$8, -24(%rbp)
	movl	$7, -20(%rbp)
	movl	$6, -16(%rbp)
	movl	$5, -36(%rbp)
	movl	-36(%rbp), %ecx
	leaq	-32(%rbp), %rax
	movl	$10, %edx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	sort
	movl	$0, -40(%rbp)
	jmp	.L17
.L18:
	movl	-40(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -40(%rbp)
.L17:
	movl	-40(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L18
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L20
	call	__stack_chk_fail@PLT
.L20:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
