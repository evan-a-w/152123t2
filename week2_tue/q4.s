	.data
number_string:
	.asciiz "Enter a number: "

	.text
main:
	li	$v0, 4
	la	$a0, number_string
	syscall # printf("Enter a number: ");

	# $t0 is x, $t1 is y

        # scanf("%d", &x);
	li	$v0, 5
	syscall
	move	$t0, $v0 # x in $t0

	# y = x * x
	mul	$t1, $t0, $t0
;; labl:
	li	$v0, 1
	move	$a0, $t1
	syscall #printf("%d", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall

	;; j	labl

	li	$v0, 0
	jr	$ra # return 0;
