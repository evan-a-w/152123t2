	.text
main:
	# x in $t0
	li	$t0, 1
loop:
loop_cond:
	bgt	$t0, 100, loop_end
loop_body:
	li	$v0, 1
	move	$a0, $t0
	syscall # printf("%d", x) ;

	li	$v0, 11
	li	$a0, '\n'
	syscall # printf("\n")	;

loop_increment:
	add	$t0, $t0, 1 # x++ ;

	j	loop
loop_end:

	li	$v0, 0
	jr	$ra
