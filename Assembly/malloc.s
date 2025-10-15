	.file	"malloc.c"
	.option nopic
	.attribute arch, "rv32i2p1_m2p0_a2p1_c2p0_zmmul1p0_zaamo1p0_zalrsc1p0_zca1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	addi	s0,sp,16
	call	DynamicMemoryAllocation
	li	a5,0
	mv	a0,a5
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	main, .-main
	.section	.rodata
	.align	2
.LC0:
	.string	"Enter how many grades youd like to enter: "
	.align	2
.LC1:
	.string	"%d"
	.align	2
.LC2:
	.string	"ERROR: Malloc failed to allocate memory"
	.align	2
.LC3:
	.string	"Enter grades number #%d: "
	.align	2
.LC4:
	.string	" %c"
	.align	2
.LC5:
	.string	"Grades[%d] : %c\n"
	.text
	.align	1
	.globl	DynamicMemoryAllocation
	.type	DynamicMemoryAllocation, @function
DynamicMemoryAllocation:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	sw	zero,-32(s0)
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	addi	a5,s0,-32
	mv	a1,a5
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	scanf
	lw	a5,-32(s0)
	mv	a0,a5
	call	malloc
	mv	a5,a0
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	bne	a5,zero,.L4
	lui	a5,%hi(.LC2)
	addi	a0,a5,%lo(.LC2)
	call	puts
	li	a5,1
	j	.L10
.L4:
	sw	zero,-20(s0)
	j	.L6
.L7:
	lw	a5,-20(s0)
	addi	a5,a5,1
	mv	a1,a5
	lui	a5,%hi(.LC3)
	addi	a0,a5,%lo(.LC3)
	call	printf
	lw	a5,-20(s0)
	lw	a4,-28(s0)
	add	a5,a4,a5
	mv	a1,a5
	lui	a5,%hi(.LC4)
	addi	a0,a5,%lo(.LC4)
	call	scanf
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L6:
	lw	a5,-32(s0)
	lw	a4,-20(s0)
	blt	a4,a5,.L7
	sw	zero,-24(s0)
	j	.L8
.L9:
	lw	a5,-24(s0)
	addi	a3,a5,1
	lw	a5,-24(s0)
	lw	a4,-28(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	mv	a2,a5
	mv	a1,a3
	lui	a5,%hi(.LC5)
	addi	a0,a5,%lo(.LC5)
	call	printf
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L8:
	lw	a5,-32(s0)
	lw	a4,-24(s0)
	blt	a4,a5,.L9
	lw	a0,-28(s0)
	call	free
	sw	zero,-28(s0)
	li	a5,0
.L10:
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	DynamicMemoryAllocation, .-DynamicMemoryAllocation
	.ident	"GCC: (g1b306039a) 15.1.0"
	.section	.note.GNU-stack,"",@progbits
