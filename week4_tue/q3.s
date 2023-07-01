	.data
arr:
	.word 1, 2, 3

	.text
main:
	push	$ra

	la	$a0, arr
	li	$a1, 3
	jal	max

	# $v0 = max({1, 2, 3})
	move	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 0

	pop	$ra
	jr	$ra


# int max(int array[], int length) ;
max:
max__prologue:
	push	$ra
	push	$s0

max__body:
	lw	$s0, ($a0) # $s0 = array[0]

	bgt	$a1, 1, length_greater_than_one
	move	$v0, $s0
	j	max__epilogue
length_greater_than_one:
	add	$a0, $a0, 4
	add	$a1, $a1, -1
	jal	max
	# max(&array[1], length - 1);
	# max_so_far in $v0

	ble	$s0, $v0, first_element_leq
	move	$v0, $s0
first_element_leq:
max__epilogue:
	pop	$s0
	pop	$ra

	jr	$ra
