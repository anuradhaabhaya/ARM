	.file	"kernel.c"
	.text
	.globl	kernel3
	.type	kernel3, @function
kernel3:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	fldl	(%eax)
	movl	16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	20(%ebp), %eax
	fstpl	(%eax)
	movl	$1, -8(%ebp)
	jmp	.L2
.L3:
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-8(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-8(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fmulp	%st, %st(1)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -8(%ebp)
.L2:
	movl	-8(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jl	.L3
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	.L4
.L5:
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-8(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-8(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -8(%ebp)
.L4:
	movl	-8(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L5
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	kernel3, .-kernel3
	.globl	kernel2
	.type	kernel2, @function
kernel2:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	fldl	(%eax)
	movl	16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	20(%ebp), %eax
	fstpl	(%eax)
	movl	$1, -4(%ebp)
	jmp	.L7
.L8:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fmulp	%st, %st(1)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L7:
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-4(%ebp), %eax
	jg	.L8
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%ebp)
	jmp	.L9
.L10:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L9:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L10
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	kernel2, .-kernel2
	.globl	kernel1
	.type	kernel1, @function
kernel1:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L12
.L13:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fmulp	%st, %st(1)
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L12:
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-4(%ebp), %eax
	jg	.L13
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%ebp)
	jmp	.L14
.L15:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	faddp	%st, %st(1)
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L14:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L15
	movl	$1, -4(%ebp)
	jmp	.L16
.L17:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	20(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L16:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L17
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	kernel1, .-kernel1
	.globl	kernel0
	.type	kernel0, @function
kernel0:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L19
.L22:
	movl	8(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-4(%ebp), %eax
	jle	.L20
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fmulp	%st, %st(1)
	fstpl	(%eax)
	jmp	.L21
.L20:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	faddp	%st, %st(1)
	fstpl	(%eax)
.L21:
	addl	$1, -4(%ebp)
.L19:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L22
	movl	$1, -4(%ebp)
	jmp	.L23
.L24:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	20(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	20(%ebp), %edx
	addl	%ecx, %edx
	fldl	(%edx)
	fadd	%st(0), %st
	fstpl	(%eax)
	addl	$1, -4(%ebp)
.L23:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L24
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	kernel0, .-kernel0
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
