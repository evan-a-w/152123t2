	.text
main:
	li	$v0, 4
	la	$a0, string
	syscall


	li	$v0, 0
	jr	$ra # return 0;

	.data
string:
	.asciiz "Hello world!\n"
string2:
	.asciiz "string two"
