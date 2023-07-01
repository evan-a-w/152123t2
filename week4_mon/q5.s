	.text
main:
main_prologue:
	# save $ra because its not a leaf function
	push	$ra
main_body:
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4 # changes $ra, result in $v0

	move	$a0, $v0 # $a0 is the result of sum4
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main_epilogue:
	# pops must be in the reverse order as pushes
	pop	$ra

	li	$v0, 0
	jr	$ra

sum4:
	# a in $a0
	# b in $a1
	# c in $a2
	# d in $a3
sum4_prologue:
	# we use $s0, $s1 and $s2
	# push $ra if we use jal
	# push all the $s registers we use
	push	$s0
	push	$s1
	push	$s2
	push	$s3
	push	$ra

	move	$s0, $a2 # c in $s0
	move	$s1, $a3 # d in $s1
sum4_body:
	# a0 is a, a1 is b
	jal	sum2 # v0 = sum2(a, b)
	move	$s2, $v0 # sum2(a, b) in $s2

	move	$a0, $s0
	move	$a1, $s1

	# the stuff with $t0 here is an alternative to $s registers
	li	$t0, 3
	push	$t0
	jal	sum2
	pop	$t0

	move	$s3, $v0 # sum2(c, d) in $s3

	move	$a0, $s2
	move	$a1, $s3
	jal	sum2 # $v0 is sum2(res1, res2)

	# now we can't trust $t and $a registers
sum4_epilogue:
	# this is the reverse order of the pushes
	pop	$ra
	pop	$s3
	pop	$s2
	pop	$s1
	pop	$s0

	jr	$ra

sum2:
	# x is in $a0, y is in $a1
	# $v0 is x + y
	add	$v0, $a0, $a1
	jr	$ra
