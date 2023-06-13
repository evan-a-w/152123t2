	.data
N_SIZE = 10

numbers:
	.word	0:N_SIZE
	# .space	N_SIZE * 4

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
	# scanf("%d", $v0)

	# numbers[i] = $v0
	mul	$t1, $t0, 4 # $t1 = i * sizeof(element) = i * 4

	# la	$t2, numbers
	# add	$t2, $t1, $t2
	# sw	$v0, ($t2)
	sw	$v0, numbers($t1) # numbers + i * 4 = $v0
read_loop_increment:
	add	$t0, $t0, 1
	j	read_loop_start
read_loop_end:

	li	$t0, 0
print_loop_start:
print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end
print_loop_body:
	# numbers[i] = $v0
	mul	$t1, $t0, 4 # $t1 = i * sizeof(element) = i * 4
	lw	$a0, numbers($t1)
	# $a0 = numbers[i]

	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall


print_loop_increment:
	add	$t0, $t0, 1
	j	print_loop_start
print_loop_end:


	li	$v0, 0
	jr	$ra
