	.data
arr:
	.word 1,2,3
	.text
main:
	push	$ra

	la	$a0, arr
	li	$a1, 3
	jal	max

	move	$a0, $v0
	li	$v0, 1
	syscall

	pop	$ra
	li	$v0, 0
	jr	$ra


max:
	# $a0, address of an int array array
	# $a1 has the length
max_prologue:
	push	$ra
	push	$s0
	push	$s1

	move	$s0, $a0
	move	$s1, $a1
max_body:
	lw	$v0, ($a0) # first_element in $v0
	beq	$a1, 1, max_epilogue # return first_element
	# if (length == 1) return first_element;

	add	$a0, $s0, 4 # $a0 = array + 4 == &array[1]
	add	$a1, $s1, -1 # $a1 = length - 1
	jal	max

	# max_so_far in $v0

	lw	$t0, ($s0) # first_element in $t0
	ble	$t0, $v0, first_element_leq

	move	$v0, $t0

first_element_leq:
max_epilogue:
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra
