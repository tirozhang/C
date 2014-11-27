	.file	"myCopy.c"
	.section	.rodata
.LC0:
	.string	"Usage:%s src dest\n"
.LC1:
	.string	"rb"
.LC2:
	.string	"Cant open \"%s\" file"
.LC3:
	.string	"wb"
.LC4:
	.string	"Cant write \"%s\" file"
.LC5:
	.string	"copy ok!"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	%ecx, -28(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -8(%ebp)
	movl	-28(%ebp), %eax
	cmpl	$3, (%eax)
	je	.L2
	movl	-28(%ebp), %edx
	movl	4(%edx), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	jmp	.L4
.L2:
	movl	-28(%ebp), %edx
	movl	4(%edx), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	$.LC1, 4(%esp)
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	.L5
	movl	-28(%ebp), %edx
	movl	4(%edx), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	jmp	.L4
.L5:
	movl	-28(%ebp), %edx
	movl	4(%edx), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	$.LC3, 4(%esp)
	movl	%eax, (%esp)
	call	fopen
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L9
	movl	-28(%ebp), %edx
	movl	4(%edx), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	jmp	.L4
.L10:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	fputc
.L9:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	fgetc
	movl	%eax, -8(%ebp)
	cmpl	$-1, -8(%ebp)
	jne	.L10
	movl	$.LC5, (%esp)
	call	printf
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	fclose
	movl	$0, -24(%ebp)
	jmp	.L12
.L4:
	movl	$1, -24(%ebp)
.L12:
	movl	-24(%ebp), %eax
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-54)"
	.section	.note.GNU-stack,"",@progbits
