	.data
FLAG_ROWS = 6
FLAG_COLS = 12

flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

	.text
main:
row_loop_init:
	li	$t0, 0
row_loop:
row_loop_cond:
	bge	$t0, FLAG_ROWS, row_loop_end
row_loop_body:

col_loop_init:
	li	$t1, 0
col_loop:
col_loop_cond:
	bge	$t1, FLAG_COLS, col_loop_end

col_loop_body:

	# work out flag[row][col]
	# &arr[x] = arr + x * sizeof(element)
	# arr[i][j] ith row, jth column
	# skip i rows and j elements
	# how many elements in a row? num_columns
	# i * num_col elements skipped per row
	# i * num_col + j is total number of elements skipped
	# &arr[i][j] = arr + (i * num_col + j) * sizeof(element)
	mul	$t2, $t0, FLAG_COLS # i * num_col in $t2
	add	$t2, $t2, $t1 # (i * num_col + j) in $t2
	# (i * num_col + j) * (sizeof(element) = 1) in $t2

	lb	$a0, flag($t2) # flag[row][col] in $a0
	li	$v0, 11
	syscall

col_loop_incr:
	add	$t1, $t1, 1

	j	col_loop
col_loop_end:

	li	$v0, 11
	li	$a0, '\n'
	syscall # printf("\n");

row_loop_incr:
	add	$t0, $t0, 1

	j	row_loop
row_loop_end:
	li	$v0, 0
	jr	$ra
