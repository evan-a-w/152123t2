	.data
	.text
main:
main__prologue:
	push	$ra
main__body:

	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4

	move	$a0, $v0
	li	$v0, 1
	syscall


main__epilogue:
	pop	$ra

	li	$v0, 0
	jr	$ra

#            $a0    $a1 ....
# int sum4(int a, int b, int c, int d)

#Args : void
#
#Returns : void
#
# frame is just all the things we push and pop
# Frame : [$ra, $s0, $s1, $s2]

# all teh registers we use
# Usses : [$ra, $s0, $s1, $s2, $a0, $a1, $a2, $a3, $v0]
# clobbers are all the registers we change the value of (dont include
# the clobbers of functions you call)
# Clobbers : [$a0, $a1]
#
#Locals:
#-res1 in $s2
#-res2 in $v0
#
#Structure:
#print_welcome
#->[prologue]
#->body
#  -> row_loop
#     -> col_loop
#->[epilogue]
sum4:
sum4__prologue:
	push	$ra
	push	$s0
	push	$s1
	push	$s2

sum4__body:
	move	$s0, $a2
	move	$s1, $a3

	move	$a0, $a0
	move	$a1, $a1 # this is obviously the same as doing nothing

	jal	sum2 # int res1 = sum2(a, b)

	move	$s2, $v0
	# res1 in $s2
	# a2, a3 might have changed
	# now thats fine, because these are in s registers

	move	$a0, $s0
	move	$a1, $s1
	jal	sum2
	# $v0 will be res2 = sum2(c, d)

	move	$a0, $s2
	move	$a1, $v0
	jal	sum2

sum4__epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra

# int sum2(int x, int y)
sum2:
	# x in $a0
	# y in $a1
	add	$v0, $a0, $a1
	jr	$ra
