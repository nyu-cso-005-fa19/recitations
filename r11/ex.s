_f_ma:                                  ## @f_ma
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rsi, %rax
	imulq	%rdx, %rax
	addq	(%rdi), %rax
	movq	%rax, (%rdi)
	popq	%rbp
	retq
_main:                                  ## @main
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movq	$5, -8(%rbp)
	leaq	-8(%rbp), %rdi
	movl	$7, %esi
	movl	$11, %edx
	callq	_f_ma
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
