	.text
main:
	# x in $t0, y in $t1

	# load a string to printf
	la	$a0, enter_string
	li	$v0, 4 # print syscall
	syscall

	li	$v0, 5
	syscall

	# in $v0 is an int that we read in
	move	$t0, $v0 # $t0 = $v0
	# scanf("%d", &x);

	mul	$t1, $t0, $t0 # t1 = t0 * t0

	# printf("%d", y);
	move	$a0, $t1
	li	$v0, 1
	syscall

	# printf("%c", '\n');
	li	$v0, 11
	li	$a0, '\n'
	syscall

	# return 0;
	li	$v0, 0
	jr	$ra

	.data
enter_string:
	.asciiz "Enter a number: "
