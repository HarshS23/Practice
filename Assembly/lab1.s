	.file	"lab1.c"
	.option nopic
	.attribute arch, "rv32i2p1_m2p0_a2p1_c2p0_zmmul1p0_zaamo1p0_zalrsc1p0_zca1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	2
.LC0:
	.string	"invalid"
	.align	2
.LC1:
	.string	"Airline"
	.align	2
.LC2:
	.string	"Airline & Financials"
	.align	2
.LC3:
	.string	"Banking & financials (Diner's club)"
	.align	2
.LC4:
	.string	"Banking & financials (Visa)"
	.align	2
.LC5:
	.string	"Banking & financials (MasterCard)"
	.align	2
.LC6:
	.string	"Merchandising & financials (Discover)"
	.align	2
.LC7:
	.string	"ERROR"
	.text
	.align	1
	.globl	creditValid
	.type	creditValid, @function
creditValid:
	addi	sp,sp,-144
	sw	ra,140(sp)
	sw	s0,136(sp)
	addi	s0,sp,144
	sw	a0,-136(s0)
	sw	a1,-132(s0)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	j	.L2
.L3:
	lw	a4,-136(s0)
	lw	a5,-132(s0)
	li	a2,10
	li	a3,0
	mv	a0,a4
	mv	a1,a5
	call	__moddi3
	mv	a4,a0
	mv	a5,a1
	mv	a2,a4
	mv	a3,a5
	lw	a5,-20(s0)
	addi	a4,a5,1
	sw	a4,-20(s0)
	mv	a3,a2
	addi	a4,s0,-120
	slli	a5,a5,2
	add	a5,a5,a4
	sw	a3,0(a5)
	lw	a4,-136(s0)
	lw	a5,-132(s0)
	li	a2,10
	li	a3,0
	mv	a0,a4
	mv	a1,a5
	call	__divdi3
	mv	a4,a0
	mv	a5,a1
	sw	a4,-136(s0)
	sw	a5,-132(s0)
.L2:
	lw	a5,-132(s0)
	bgt	a5,zero,.L3
	lw	a5,-132(s0)
	bne	a5,zero,.L20
	lw	a5,-136(s0)
	bne	a5,zero,.L3
.L20:
	sw	zero,-28(s0)
	j	.L5
.L6:
	lw	a4,-28(s0)
	addi	a5,s0,-120
	slli	a4,a4,2
	add	a5,a4,a5
	lw	a5,0(a5)
	sw	a5,-44(s0)
	lw	a4,-20(s0)
	lw	a5,-28(s0)
	sub	a5,a4,a5
	addi	a4,a5,-1
	addi	a5,s0,-120
	slli	a4,a4,2
	add	a5,a4,a5
	lw	a4,0(a5)
	lw	a3,-28(s0)
	addi	a5,s0,-120
	slli	a3,a3,2
	add	a5,a3,a5
	sw	a4,0(a5)
	lw	a4,-20(s0)
	lw	a5,-28(s0)
	sub	a5,a4,a5
	addi	a4,a5,-1
	addi	a5,s0,-120
	slli	a4,a4,2
	add	a5,a4,a5
	lw	a4,-44(s0)
	sw	a4,0(a5)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L5:
	lw	a5,-20(s0)
	srli	a4,a5,31
	add	a5,a4,a5
	srai	a5,a5,1
	mv	a4,a5
	lw	a5,-28(s0)
	blt	a5,a4,.L6
	sw	zero,-32(s0)
	j	.L7
.L9:
	lw	a4,-32(s0)
	addi	a5,s0,-120
	slli	a4,a4,2
	add	a5,a4,a5
	lw	a5,0(a5)
	sw	a5,-36(s0)
	lw	a4,-20(s0)
	lw	a5,-32(s0)
	sub	a5,a4,a5
	andi	a5,a5,1
	bne	a5,zero,.L8
	lw	a5,-36(s0)
	slli	a5,a5,1
	sw	a5,-36(s0)
	lw	a4,-36(s0)
	li	a5,9
	ble	a4,a5,.L8
	lw	a5,-36(s0)
	addi	a5,a5,-9
	sw	a5,-36(s0)
.L8:
	lw	a4,-24(s0)
	lw	a5,-36(s0)
	add	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-32(s0)
	addi	a5,a5,1
	sw	a5,-32(s0)
.L7:
	lw	a4,-32(s0)
	lw	a5,-20(s0)
	blt	a4,a5,.L9
	lw	a3,-24(s0)
	li	a5,1717985280
	addi	a5,a5,1639
	mulh	a5,a3,a5
	srai	a4,a5,2
	srai	a5,a3,31
	sub	a4,a4,a5
	mv	a5,a4
	slli	a5,a5,2
	add	a5,a5,a4
	slli	a5,a5,1
	sub	a4,a3,a5
	beq	a4,zero,.L10
	lui	a5,%hi(.LC0)
	addi	a5,a5,%lo(.LC0)
	j	.L19
.L10:
	lw	a5,-120(s0)
	sw	a5,-40(s0)
	lw	a4,-40(s0)
	li	a5,6
	beq	a4,a5,.L12
	lw	a4,-40(s0)
	li	a5,6
	bgt	a4,a5,.L13
	lw	a4,-40(s0)
	li	a5,5
	beq	a4,a5,.L14
	lw	a4,-40(s0)
	li	a5,5
	bgt	a4,a5,.L13
	lw	a4,-40(s0)
	li	a5,4
	beq	a4,a5,.L15
	lw	a4,-40(s0)
	li	a5,4
	bgt	a4,a5,.L13
	lw	a4,-40(s0)
	li	a5,3
	beq	a4,a5,.L16
	lw	a4,-40(s0)
	li	a5,3
	bgt	a4,a5,.L13
	lw	a4,-40(s0)
	li	a5,1
	beq	a4,a5,.L17
	lw	a4,-40(s0)
	li	a5,2
	beq	a4,a5,.L18
	j	.L13
.L17:
	lui	a5,%hi(.LC1)
	addi	a5,a5,%lo(.LC1)
	j	.L19
.L18:
	lui	a5,%hi(.LC2)
	addi	a5,a5,%lo(.LC2)
	j	.L19
.L16:
	lui	a5,%hi(.LC3)
	addi	a5,a5,%lo(.LC3)
	j	.L19
.L15:
	lui	a5,%hi(.LC4)
	addi	a5,a5,%lo(.LC4)
	j	.L19
.L14:
	lui	a5,%hi(.LC5)
	addi	a5,a5,%lo(.LC5)
	j	.L19
.L12:
	lui	a5,%hi(.LC6)
	addi	a5,a5,%lo(.LC6)
	j	.L19
.L13:
	lui	a5,%hi(.LC7)
	addi	a5,a5,%lo(.LC7)
.L19:
	mv	a0,a5
	lw	ra,140(sp)
	lw	s0,136(sp)
	addi	sp,sp,144
	jr	ra
	.size	creditValid, .-creditValid
	.section	.rodata
	.align	2
.LC8:
	.string	"Please enter a number (Max 16 digits): "
	.align	2
.LC9:
	.string	" %lld"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	lui	a5,%hi(.LC8)
	addi	a0,a5,%lo(.LC8)
	call	printf
	addi	a5,s0,-32
	mv	a1,a5
	lui	a5,%hi(.LC9)
	addi	a0,a5,%lo(.LC9)
	call	scanf
	lw	a4,-32(s0)
	lw	a5,-28(s0)
	mv	a0,a4
	mv	a1,a5
	call	creditValid
	sw	a0,-20(s0)
	lw	a0,-20(s0)
	call	puts
	li	a5,0
	mv	a0,a5
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.globl	__divdi3
	.globl	__moddi3
	.ident	"GCC: (g1b306039a) 15.1.0"
	.section	.note.GNU-stack,"",@progbits
