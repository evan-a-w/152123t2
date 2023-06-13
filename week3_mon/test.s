	.text
main:
	li	$a0, 'a'
	li	$v0, 11
	syscall
label:
loop_start:
	li	$a0, '\n'
	li	$v0, 11
	syscall
	
	li	$v0, 0
	jr	$ra

    .data
# 0
# int a = 42;
a:  .word   42
# 4
b:  .space  4
# 8
c:  .asciiz "abcde"
# 14 isnt a multiple of 4
z:	.word 4
    .align  2
# this is now fine
z:	.word 4
d:  .byte   1, 2, 3, 4
e:  .word   1, 2, 3, 4
f:  .space  1

Give MIPS directives to represent the following variables:

int u;
u:	.space 4


int v = 42;
v:	.word 42
char w;
w:	.space 1
char x = 'a';
x:	.byte 'a'
double y;
y:	.space 8

int z[20];
z:	.word 0, 0, 0, 0
z:	.space 80

Address       Data Definition
0x10010000    aa:  .word 42
0x10010004    bb:  .word 666
0x10010008    cc:  .word 1
0x1001000C         .word 3
0x10010010         .word 5
0x10010014         .word 7

lw # load word (get from memory)
sw # store word (put into memory)
lb # byte
sb # byte
lh # half word (2 bytes) (we never use this)
sh # half word

la   $t0, aa  # address of aa in $t0, 0x10010000
lw   $t0, bb  # loads a word from bb into $t0 - $t0 = 666
lb   $t0, bb  # $t0 = 154
lw   $t0, aa+4 # aa + 4 = bb, $t0 = 666
la   $t1, cc  # $t1 = cc = 0x10010008
# load from the address stored in $t1
lw   $t0, ($t1) # access memory from $t1, load from cc, $t1 = 1
la   $t1, cc
lw   $t0, 8($t1) # load from value of $t1 + 8, $t0 = 5
li   $t1, 8
lw   $t0, cc($t1) # value of $t1 + cc = 0x10010008 + 8, $t0 = 5
la   $t1, cc
	# this would die
lw   $t0, 2($t1)
