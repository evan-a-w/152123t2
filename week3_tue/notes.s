    .data
# 10
a:  .word   42
# 14
b:  .space  4
# 18
c:  .asciiz "abcde"
# 24
.space 1
# 25
    .align  2
# 28
# if we access 4 bytes of memory, the address must be divisible by 4
# .align n pads until the address is divisible by 2^n
# .align 1 makes it divisble by 2, .algin 2 makes it divisible by 4
d:  .word   1, 2, 3, 4
# 4 words, each of which is 4 bytes, 16 bytes
# 44
e:  .byte   1, 2, 3, 4
# 48
f:  .space  1
# 49


int u;
	.word 0
	.space 4
int v = 42;
	.word 42
char w;
	.space 1
	.byte 0
char x = 'a';
	.byte 'a'
	.ascii "a"
double y;
	.space 4

int z[20];
	.word 0:20
	.space 80

&a[i][j] = a + i * sizeof(element) * num_cols + j * sizeof(element) = a + (i * num_cols + j) * sizeof(element)
&a[i] = a + i * sizeof(element)

# lw = load word (from memory)
# sw = store word (into memory)
# lb = load byte..

la   $t0, aa
 
lw   $t0, bb # load from address bb into register $t0
sw   $t0, bb # store the value in $t0 into the address of bb

lb   $t0, bb
lw   $t0, aa+4
la   $t1, cc
lw   $t0, ($t1) # loading from the address in $t1, into $t0
la   $t1, cc
lw   $t0, 8($t1) # address is $t1 + 8
li   $t1, 8
lw   $t0, cc($t1) # address of cc + $t1
la   $t1, cc
lw   $t0, 2($t1)
