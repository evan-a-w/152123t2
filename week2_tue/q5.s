SQUARE_MAX = 46340

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

        # if (x <= SQUARE_MAX) goto otherwise;
	ble	$t0, SQUARE_MAX, otherwise

square_too_big:
	li	$v0, 4
	la	$a0, too_big_string
	syscall # printf("square too big for 32 bits\n");

	j	end
otherwise:
	# y = x * x
	mul	$t1, $t0, $t0
	li	$v0, 1
	move	$a0, $t1
	syscall #printf("%d", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall

end:

	li	$v0, 0
	jr	$ra # return 0;

	.data
number_string:
	.asciiz "Enter a number: "
too_big_string:
	.asciiz "square too big for 32 bits\n"
