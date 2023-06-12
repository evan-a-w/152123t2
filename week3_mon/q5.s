	.data
N_SIZE = 10

numbers:
	.space N_SIZE*4

	.text
main:
	# i in $t0
	li	$t0, 0

read_loop_start:
read_loop_cond:
	bge	$t0, N_SIZE, read_loop_end

read_loop_body:
	li	$v0, 5
	syscall
	# $v0 has int read in

	# numbers[i] = $v0
	# work out the address of numbers[i] (&numbers[i])
	la	$t1, numbers
	# $t1 + 4 * i
	mul	$t2, $t0, 4 # $t2 = 4 * i
	add	$t1, $t1, $t2 # $t1 = numbers + 4 * i = &numbers[i]

	sw	$v0, ($t1)
	sw	$v0, numbers($t2) # numbers + $t2 = numbers + 4 * i


	# scanf("%d", &numbers[i]) ;


	add	$t0, $t0, 1
	j	read_loop_start
read_loop_end:

	li	$t0, 0
print_loop_start:
print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end
print_loop_body:
	mul	$t2, $t0, 4 # $t2 = 4 * i

	# load from numbers[i] into $t1
	lw	$t1, numbers($t2)

	li	$v0, 1
	move	$a0, $t1
	syscall
	# printf("%d", numbers[i]);

	li	$v0, 11
	li	$a0, '\n'
	syscall
	# printf("\n");

	add	$t0, $t0, 1
	j	print_loop_start
print_loop_end:

	li	$v0, 0
	jr	$ra
