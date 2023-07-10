	.text
main:
	li	$v0, 4
	la	$a0, enter_number
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0 # $t0 has x


        # if x <= 100 || x >= 1000 skip medium
	ble	$t0, 100, small_big
	bge	$t0, 1000, small_big
medium:
	li	$v0, 4
	la	$a0, medium_string
	syscall

	j	end
small_big:
	li	$v0, 4
	la	$a0, small_big_string
	syscall


end:
	li	$v0, 0
	jr	$ra

	.data
enter_number:
	.asciiz "Enter a number: "
medium_string:
	.asciiz "medium\n"
small_big_string:
	.asciiz "small/big\n"

.byte	1
	.align	2
# address is now divisible by 2^2
.word	1

	sw	address, 1
	sb	address, 1
