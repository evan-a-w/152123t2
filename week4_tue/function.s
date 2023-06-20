	.text

do_something:
# where we push things is the prologue
do_something__prologue:
	push	$ra
	push	$s0 # save value

do_something__body:
	li	$t0, 0
	li	$s0, 0
	move	$a0, 1
	jal	function
	# we don't know what $t0 is now
	# we do know that $s0 is 0

	# you can do this instead of using $s registers
	push	$t0
	jal	function
	pop	$t0

	li	$v0, 0

# where we pop things is the prologue
do_something__epilogue:
	# pops in the reverse order of the pushes
	pop	$s0 # restore value
	pop	$ra

	jr	$ra


# void function(int a);
function:
	# a in $a0
	li	$t0, 2
	jr	$ra
